#ifndef UNIFORM_MESH_H_
#define UNIFORM_MESH_H_

#include <iostream>
#include <string>
#include <vector>

#include "IMesh.h"

class UniformMesh : public IMesh 
{
    protected:
        //Parameters
        float dt;
        float dx;
        float x_min;
        float x_max;
        float t_ini;
        float t_final;
        

    public:
        //Constructor

        UniformMesh();
        UniformMesh(float t_ini, float t_final, float dt, float x_min, float x_max, float dx);

        //Destructor

        ~UniformMesh();

        //Methods   

        float get_dt() override;
        float get_dx() override;
        float get_x_min() override;
        float get_x_max() override;
        float get_t_ini() override;
        float get_t_final() override;
        

        int x_size() override;
        float x_i(int i) override;
};

#endif