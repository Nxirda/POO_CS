#include <iostream>

#ifndef IMESH_H_
#define IMESH_H_

class IMesh
{
    public : 
        //Abstract Methods 
        virtual float get_t_ini() {return -1;};
        virtual float get_t_final() {return -1;};
        virtual float get_dt() {return -1;};
        virtual float get_x_min() {return -1;};
        virtual float get_x_max() {return -1;};
        virtual float get_dx() {return -1;};

        virtual int x_size() {return -1;};
        virtual float x_i(int i) {return -i;};
        
        //Destructor
        virtual ~IMesh() = default;

};

#endif