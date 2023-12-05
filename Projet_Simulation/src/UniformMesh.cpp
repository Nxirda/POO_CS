#include "UniformMesh.h"


/* Constructor */
UniformMesh::UniformMesh()
{
    this->t_ini = 0;
    this->t_final = 1;
    this->dt = 0.5;
    this->x_min = 0;
    this->x_max = 5;
    this->dx = 2;
}

/* Constructor to set values manually */
UniformMesh::UniformMesh(float tI, float tF, float dtI, float xI, float xF, float dxI)
{
    this->t_ini = tI;
    this->t_final = tF;
    this->dt = dtI;
    this->x_min = xI;
    this->x_max = xF;
    this->dx = dxI;
}

/* Destructor */
UniformMesh::~UniformMesh(){};

/* Return time steps */
float UniformMesh::get_dt() 
{
    return this->dt;
}

/* Returns space steps */
float UniformMesh::get_dx() 
{
    return this->dx;
}

/* Returns Initial Time */
float UniformMesh::get_t_ini() 
{
    return this->t_ini;
}

/* Returns Final time */
float UniformMesh::get_t_final() 
{
    return this->t_final;
}

/* Returns Initial Position */
float UniformMesh::get_x_min() 
{
    return this->x_min;
}

/* Returns Final Position */
float UniformMesh::get_x_max() 
{
    return this->x_max;
}

/* Returns the size of x */
int UniformMesh::x_size()
{
    return ((this->get_x_max() - this->get_x_min())/this->get_dx())+1; 
}

/* Returns the value of x_i depending on i */
float UniformMesh::x_i(int i) 
{
    if(this->get_x_min() + i*this->get_dx() > this->get_x_max())
    {
        return -1;
    }
    return this->get_x_min() + i*this->get_dx();
}