#include "Variable.h"
#include <fstream>
#include <string>

/* Default Constructor */
Variable::Variable()
{
    this->m_name = "";
    this->mesh = nullptr;
    this->variable = std::vector<float>();
}

/* Constructor with a mesh pointer and a size */
Variable::Variable(IMesh *mesh, int MeshSize, std::string str)
{
    this->m_name = str;
    this->mesh = mesh;
    this->variable = std::vector<float> (MeshSize);

    for(int i = 0; i < MeshSize; ++i)
    {
        this->variable[i] = mesh->get_t_ini() + i;
    }
}

/* Re defining the bracket operator */
float &Variable::operator[](int idx)
{
    return variable[idx];   
}

/* Variable getter : return variable vector */
std::vector<float> Variable::get_variable()
{
    return this->variable;
}

/* Mesh getter : return a pointer to the mesh */
IMesh* Variable::get_mesh()
{
    return this->mesh;
}

/* Name getter : returns a string of the name */
std::string Variable::get_Name()
{
    return this->m_name;
}

/* Element Setter : Sets the element at the i position in the vector */
void Variable::set_I_elem(unsigned long i, float value)
{
    if(i < this->variable.size())
    {
        this->variable[i] = value;
    }
}

/* Name setter : sets the name */
void Variable::set_M_name(std::string str)
{
    this->m_name = str;
}

/* Printer for Variable class */
#ifndef NDEBUG 

void Variable::print_in_file(float iteration_Value)
{
    // Declaration of the output files
    std::string str = "../Results/Variable_"+this->get_Name()+"-"+std::to_string(iteration_Value)+".dat";
    std::ofstream ofs(str, std::ofstream::out);

    std::cout << "= Variable name is : " << this->get_Name() << " =\n";
    for(unsigned long i = 0; i < this->get_variable().size();  ++i)
    {
        std::cout << "-- at x_i = " << this->get_variable()[i] << "\n";
        ofs<< this->get_variable()[i] << "\n";
    }
    ofs.close();    
}
#else

void Variable::print_in_file(float) {}

#endif

/**/
/* Variable& Variable::operator=(const Variable &v){
    //this->m_name = "new_Var";
    this->mesh = v.mesh;
    this->variable = v.variable;
    return *this;
}  */