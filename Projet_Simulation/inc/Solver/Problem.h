#ifndef PROBLEM_H_
#define PROBLEM_H_

#include <iostream>
#include <string>
#include <vector>

#include "Equation.h"
#include "UniformMesh.h"
#include "Variable.h"

class Problem 
{
    protected:
        //Parameters

        Equation eq;
        IMesh* mesh;

    public :
        //Constructor

        Problem (Equation equation, IMesh *IMesh);

        //Copy constructor blocked

        Problem(Problem const& a) = delete;

        //Copy assignment blocked

        Problem& operator= (Problem const& a) = delete;

        //Getters

        IMesh* get_Mesh();
        Equation get_Equation();

        //Setters

        void set_Mesh(IMesh* Im);
        void set_Equation(Equation e);

        //Destructor

        ~Problem();

        //Methods
        
        void solve_parallel();
};

#endif