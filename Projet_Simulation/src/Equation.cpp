#include <iostream>
#include <cmath>

#include "Equation.h"

/* Constructor */
Equation::Equation()
{
    this->speed = 1;
}

/* Destructor */
Equation::~Equation(){};

/* Get the speed */
float Equation::get_speed()
{
    return this->speed;
}

/* Set the speed */
void Equation::set_speed(float a)
{
    this->speed = a;
}

/* Compute the given Equation */
Variable Equation::compute(Variable &u_n, Variable &u_np1)
{
    float CFL = this->get_speed() * (u_n.get_mesh()->get_dt()/u_n.get_mesh()->get_dx()); 
    if(CFL != 0.5)
    {
        float a = (u_n.get_mesh()->get_dx() * 0.5)/u_n.get_mesh()->get_dt();
        this->set_speed(a);
        CFL = a * (u_n.get_mesh()->get_dt()/u_n.get_mesh()->get_dx());
    }

    u_np1.set_I_elem(0, u_n[0]*this->get_speed());

    for(int i = 1; i < u_n.get_mesh()->x_size(); ++i )
    {
        float res = u_n[i] - CFL * (u_n[i] - u_n[i-1]);
        u_np1.set_I_elem(i, res);
    }
    return u_np1;
}

/* Computes the Gaussian Advection of the given equation */
float Equation::Gaussian_Advection(float theta, float pi, float mu, float x)
{
    float exp_param = (pow((x-mu), 2))/(2* pow(theta, 2));
    return (1/(theta*sqrt(2*pi)))*exp(-exp_param);
}

/* Computes the initial conditions */
Variable Equation::compute_initial_condition(Variable &u, IMesh *mesh)
{
    float theta = 10* mesh->get_dx();
    float mu = (mesh->get_x_max() - mesh->get_x_min())/2;
    float pi = 4*atan(1);
    float x_i = 0;
    for(int i = 0; i < mesh->x_size(); ++i)
    {
        x_i = Gaussian_Advection(theta, pi, mu, mesh->x_i(i));
        u.set_I_elem(i, x_i);
    }
    return u;
}

/* Computes the exact solution */
Variable Equation::compute_exact_solution(Variable &v, IMesh *mesh, int curr_time)
{
    Variable u_exact = v; 
    u_exact.set_M_name("u_ref");
    float a = this->get_speed();

    float theta = 10* mesh->get_dx();
    float mu = (mesh->get_x_max() - mesh->get_x_min())/2;
    float pi = 4*atan(1);
    float x_i = 0;

    for(int i = 0; i < mesh->x_size(); ++i)
    {
        x_i = Gaussian_Advection(theta, pi, mu, (v[i]-(a*curr_time)));
        u_exact.set_I_elem(i,x_i);
    }
    return u_exact;

}