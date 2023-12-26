#include <thread>
#include <cmath>
#include <type_traits>
#include <concepts>
#include <future>

#include "Problem.h"    
#include "Variable.h"
#include "Equation_Implem.h"

#include "Upwind.h"
#include "Lax_Wendroff.h"

#include "Timer.h"


/* Constructor */
Problem::Problem(Equation e, IMesh *im)
{
    this->eq   = e;
    this->mesh = im;
}

/* Get Equation of the Problem */
Equation Problem::get_Equation()
{
    return this->eq;
}

/* Get Mesh of the Problem */
IMesh* Problem::get_Mesh()
{
    return this->mesh;
}

/* Set Equation of the Problem */
void Problem::set_Equation(Equation e)
{
    this->eq = e;
}

/* Sett Mesh of the Problem */
void Problem::set_Mesh(IMesh* Im)
{
    this->mesh = Im;
}

/* Destructor */
Problem::~Problem() 
{
    delete this->mesh;
}

/* Computes the Gaussian Advection for the model */
float Gaussian_Advection (float theta, float pi, float mu, float x)
{
    float exp_param = (pow((x-mu), 2))/(2* pow(theta, 2));
    return (1/(theta*sqrt(2*pi)))*exp(-exp_param);
};

/* Concept to verify if the models got an update value for safety*/
template <typename T>
concept HasUpdateMethod = requires {
    { T::update(std::declval<Variable&>(), std::declval<Variable&>(), std::declval<float>()) };
};

/* Returns the result of the Problem in a files */
/* Prints Every Iteration of the solution if not in release mode */
void Problem::solve_parallel()
{
    if(this->get_Mesh() == nullptr)
    {
        std::cout << "Mesh is a null pointer\n";
    }

    int x_size = this->get_Mesh()->x_size();

    float time_i     = this->get_Mesh()->get_t_ini();
    float time_j     = this->get_Mesh()->get_t_final();
    float time_steps = this->get_Mesh()->get_dt();

    //Order One
    Variable u_n {this->get_Mesh(), x_size, "u_n"};
    Variable u_np1{this->get_Mesh(), x_size, "u_np1"};
    //Computes initial condition for Order One
    u_n = this->get_Equation().compute_initial_condition(u_n, this->get_Mesh(), Gaussian_Advection);
    u_n.print_in_file(0);
    
    //Order Two
    Variable u_n_2nd_order {this->get_Mesh(), x_size, "u_n_2nd_order"};
    Variable u_np1_2nd_order{this->get_Mesh(), x_size, "u_np1_2nd_order"};
    //Computes initial condition for Order Two
    u_n_2nd_order = this->get_Equation().compute_initial_condition(u_n_2nd_order, this->get_Mesh(), Gaussian_Advection);

    //Reference variable with exact result in
    Variable u_ref{this->get_Mesh(), x_size, "u_ref"};
    
    //Initialize the timer
    Timer t;
    t.start();

    //Thread computing the first order approximate solution
    std::future approximate_order1 = std::async(std::launch::async,[&]()
    {
        for(float time_i = this->get_Mesh()->get_t_ini() ; time_i < time_j; time_i+= time_steps)
        {
            if constexpr (HasUpdateMethod<Upwind>) 
            {
                u_np1 = this->get_Equation().compute_for_scheme<Upwind>(u_n, u_np1, this->get_Equation().get_speed());

                //actualize u_n value 
                u_n = u_np1;
                u_n.set_M_name("u_n");
                u_np1.set_M_name("u_np1");
            }
            else
            {
                perror("Order one resolution model didnt have an update method");
                abort();
            }

        }
        u_np1.print_in_file(time_i);
    });

    //Thread computing the 2nd order approximate solution
    std::future approximate_order2 = std::async(std::launch::async,[&]()
    {
        for(float time_i = this->get_Mesh()->get_t_ini() ; time_i < time_j; time_i+= time_steps)
        {
            if constexpr (HasUpdateMethod<Lax_Wendroff>) 
            {
                u_np1_2nd_order = this->get_Equation().compute_for_scheme<Lax_Wendroff>(u_n_2nd_order, u_np1_2nd_order, this->get_Equation().get_speed());

                //actualize u_n value 
                u_n_2nd_order = u_np1_2nd_order;
                u_n_2nd_order.set_M_name("u_n_2nd_order");
                u_np1_2nd_order.set_M_name("u_np1_2nd_order");
            }
            else
            {
                perror("Order two resolution model didnt have an update method");
                abort();
            }
        }
        u_np1_2nd_order.print_in_file(time_i);
    });

    //Thread computing exact solution
    std::future exact_thread = std::async(std::launch::async,[&]()
    {

        for(float time_i = this->get_Mesh()->get_t_ini() ;time_i < time_j; time_i+= time_steps)
        {
            u_ref = this->get_Equation().compute_exact_solution(this->get_Mesh(), time_i, Gaussian_Advection);
        }
        u_ref.print_in_file(time_i);
        
    });

    //Joining the threads
    exact_thread.wait();
    approximate_order1.wait();
    approximate_order2.wait();
    
    //Stopping the timer and printing results
    t.stop();
    t.print("Temporal Loop");
}