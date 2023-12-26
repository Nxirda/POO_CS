#ifndef NON_UNIFORM_MESH_H_
#define NON_UNIFORM_MESH_H_

#include <iostream>
#include <string>
#include <vector>

#include "IMesh.h"

class NonUniformMesh : public IMesh 
{
    protected:
        //Parameters

        float dt;
        float dx;
        float t_ini;
        float x_min;
        float x_max;
        float t_final;
        

    public:
        //Constructor

        NonUniformMesh();
        NonUniformMesh(float t_ini, float t_final, float dt, float x_min, float x_max, float dx);

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