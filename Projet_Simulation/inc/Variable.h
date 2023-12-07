#include <vector>
#include <string>

#include "IMesh.h"

#ifndef VARIABLE_H_
#define VARIABLE_H_

class Variable
{
    private :
    //Parameters
    std::string m_name;
    IMesh* mesh;
    std::vector<float> variable;

    public:
    //Constructor
    Variable();
    Variable(IMesh *mesh, int MeshSize, std::string str);

    //Getters
    std::vector<float> get_variable();
    IMesh* get_mesh();
    std::string get_Name();

    //Setters
    void set_I_elem(unsigned long i, float value);
    void set_M_name(std::string str);

    //Methods
    void print_in_file(float iteration_Value);
    float &operator [](int idx);
    //Ajouter operator [] const
    //Variable &operator =(const Variable &v);

};

#endif