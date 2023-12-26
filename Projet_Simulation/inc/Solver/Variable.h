#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <vector>
#include <string>

#include "IMesh.h"

class Variable
{
    private :
        //Parameters

        IMesh* mesh;
        std::string m_name;
        std::vector<float> variable;

    public:
        //Constructor

        Variable();
        Variable(IMesh *mesh, int MeshSize, std::string str);

        //Getters
        
        IMesh* get_mesh();
        std::string get_Name();
        std::vector<float> get_variable();

        //Setters

        void set_M_name(std::string str);
        void set_I_elem(unsigned long i, float value);

        //Methods

        float &operator [](int idx);
        Variable &operator =(const Variable &v);
        void print_in_file(float iteration_Value);

};

#endif