#ifndef EQUATION_H_
#define EQUATION_H_

#include <iostream>
#include <cmath>

#include <execution>
#include <algorithm>

#include "Variable.h"

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

        template <class T>
        Variable compute_for_scheme(Variable &u_n, Variable &u_np1, float speed);

        template <typename T>
        Variable compute_initial_condition(Variable &v, IMesh *mesh, T&& lambda);

        template <typename T>
        Variable compute_exact_solution(IMesh *mesh, int curr_time, T&& lambda);
};

#endif