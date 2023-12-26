#ifndef IMESH_H_
#define IMESH_H_

#include <iostream>

class IMesh
{
    public : 
        //Abstract Methods 

        virtual int x_size() = 0; 
        virtual float get_dt() = 0; 
        virtual float get_dx() = 0; 
        virtual float x_i(int i) = 0; 
        virtual float get_x_max() = 0; 
        virtual float get_x_min() = 0; 
        virtual float get_t_ini() = 0; 
        virtual float get_t_final() = 0; 

        //Destructor
        
        virtual ~IMesh() = default;

};

#endif