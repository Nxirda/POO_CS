#include <thread>

#include "Problem.h"
#include "Variable.h"
#include "Timer.h"

/* Constructor */
Problem::Problem(Equation e, IMesh *im)
{
    this->eq = e;
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

/* Returns the result of the Problem in a files */
/* Prints Every Iteration of the solution */
void Problem::solve()
{   
    if(this->get_Mesh() == nullptr)
    {
        std::cout << "Mesh is a null pointer\n";
    }

    int x_size = this->get_Mesh()->x_size();

    //Variable that stores the x_i at a time i
    Variable u_n  {this->get_Mesh(), x_size, "u_n"};
    u_n = this->eq.compute_initial_condition(u_n, this->get_Mesh());
    u_n.print_in_file(0);

    //Variable that stores the x_i at a time i + 1
    Variable u_np1{this->get_Mesh(), x_size, "u_np1"};

    //Reference variable with exact result in
    Variable u_ref{this->get_Mesh(), x_size, "u_ref"};

    float time_i = this->get_Mesh()->get_t_ini();
    float time_j = this->get_Mesh()->get_t_final();
    float time_steps = this->get_Mesh()->get_dt();
    
    //std::cout << "=== Solve Problem ===\n";
    Timer t;
    t.start();

    for( ; time_i < time_j; time_i+= time_steps)
    {
        //std::cout << "\n--- Compute Equation at time : " << time_i << " ---\n";
        u_np1 = this->eq.compute(u_n, u_np1);
        u_ref = this->eq.compute_exact_solution(this->get_Mesh(), time_i+1);

        //actualize u_n value 
        // Override = operator at some point
        u_n = u_np1;
        u_n.set_M_name("u_n");
        u_np1.set_M_name("u_np1");
    }
    t.stop();
    t.print("Temporal Loop");

    //Output in the file 
    u_np1.print_in_file(time_i);
    u_ref.print_in_file(time_i);
}

void Problem::solve_parallel()
{
    if(this->get_Mesh() == nullptr)
    {
        std::cout << "Mesh is a null pointer\n";
    }

    int x_size = this->get_Mesh()->x_size();

    //Variable that stores the x_i at a time i
    Variable u_n  {this->get_Mesh(), x_size, "u_n"};
    u_n = this->eq.compute_initial_condition(u_n, this->get_Mesh());
    u_n.print_in_file(0);

    //Variable that stores the x_i at a time i + 1
    Variable u_np1{this->get_Mesh(), x_size, "u_np1"};

    //Reference variable with exact result in
    Variable u_ref{this->get_Mesh(), x_size, "u_ref"};
    
    float time_i = this->get_Mesh()->get_t_ini();
    float time_j = this->get_Mesh()->get_t_final();
    float time_steps = this->get_Mesh()->get_dt();
    //std::cout << "=== Solve Problem ===\n";
    Timer t;
    t.start();

    //Thread computing approximate solution
    std::thread approximate_thread([&](){
        for( ; time_i < time_j; time_i+= time_steps)
        {
            u_np1 = this->eq.compute(u_n, u_np1);

            //actualize u_n value 
            u_n = u_np1;
            u_n.set_M_name("u_n");
            u_np1.set_M_name("u_np1");
        }
    });

    //Thread computing exact solution
    std::thread exact_thread([&](){

        for( ; time_i < time_j; time_i+= time_steps)
        {
            u_ref = this->eq.compute_exact_solution(this->get_Mesh(), time_i+1);
        }
    });

    //Joining the threads
    approximate_thread.join();
    exact_thread.join();

    t.stop();
    t.print("Temporal Loop");

}