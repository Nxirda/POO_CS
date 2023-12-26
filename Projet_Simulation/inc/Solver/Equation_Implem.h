#ifndef EQUATION_IMPLEM_H_
#define EQUATION_IMPLEM_H_

#include "Equation.h"
#include "Variable.h"

/*Computes the initial condition for the equation via a given Gaussian Advection*/
template <typename T>
Variable Equation::compute_initial_condition(Variable &u, IMesh *mesh, T&& Gaussian_Advection)
{
    float theta = 10* mesh->get_dx();
    float mu = (mesh->get_x_max() - mesh->get_x_min())/2;
    float pi = 4*atan(1);
    float x_i = 0;
    
    std::vector<float> v = u.get_variable();

    std::for_each(std::execution::par, v.begin(), v.end(),[&](auto curr_elem){
        x_i = Gaussian_Advection(theta, pi, mu, mesh->x_i(curr_elem));
        u.set_I_elem(curr_elem, x_i);
    });

    return u;
}

/*Computes the equation for the solving model */
template <class T>
Variable Equation::compute_for_scheme(Variable &u_n, Variable &u_np1, float speed){
    float CFL = speed * (u_n.get_mesh()->get_dt()/u_n.get_mesh()->get_dx()); 
    if(CFL != 0.5)
    {
        float a = (u_n.get_mesh()->get_dx() * 0.5)/u_n.get_mesh()->get_dt();
        this->set_speed(a);
        CFL = a * (u_n.get_mesh()->get_dt()/u_n.get_mesh()->get_dx());
    }

    u_np1.set_I_elem(0, 0);
    u_np1 = T::update(u_n, u_np1, this->get_speed());
    
    return u_np1; 
}

/*Computes the exact solution of the equation for the given gaussian advection */
template <typename T>
Variable Equation::compute_exact_solution(IMesh *mesh, int curr_time, T&& Gaussian_Advection)
{
    Variable u_exact(mesh, mesh->x_size(), "u_ref"); 
    float a = this->get_speed();

    float theta = 10* mesh->get_dx();
    float mu = (mesh->get_x_max() - mesh->get_x_min())/2;
    float pi = 4*atan(1);
    float x_i = 0;

    std::vector<float> v = u_exact.get_variable();

    std::for_each(std::execution::par, v.begin(), v.end(),[&](auto curr_elem){
        x_i = Gaussian_Advection(theta, pi, mu, (mesh->x_i(curr_elem)-(a*curr_time)));
        u_exact.set_I_elem(curr_elem, x_i);
    }); 
    
    return u_exact;
}

#endif