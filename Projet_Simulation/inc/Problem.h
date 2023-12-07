#include <iostream>
#include <string>
#include <vector>

#include "Equation.h"
#include "UniformMesh.h"
#include "Variable.h"

#ifndef PROBLEM_H_
#define PROBLEM_H_

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
        Equation get_Equation();
        IMesh* get_Mesh();

        //Setters
        void set_Equation(Equation e);
        void set_Mesh(IMesh* Im);

        //Destructor
        ~Problem();

        //Methods
        void solve();
        void solve_parallel();

};

#endif