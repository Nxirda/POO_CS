#include <iostream>

#include "Variable.h"

#ifndef EQUATION_H_
#define EQUATION_H_

class Equation 
{
    protected:
        //Parameters
        float speed;
        
    public:
        //Constructor 
        Equation();

        //Destructor
        ~Equation();

        //Getters
        float get_speed();

        //Setters
        void set_speed(float a);
        
        //Methods
        Variable compute(Variable &u_n, Variable &u_np1);
        Variable compute_initial_condition(Variable &v, IMesh *mesh);
        Variable compute_exact_solution(Variable &v, IMesh *mesh, int curr_time);
    private:
        float Gaussian_Advection(float theta, float pi, float mu, float x);
       
};

#endif