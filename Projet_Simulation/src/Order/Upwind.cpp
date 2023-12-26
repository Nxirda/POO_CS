#include "Upwind.h"
    
/* Computes the element at time n plus 1 following the Upwind Model*/
Variable Upwind::update(Variable &u_n, Variable &u_np1, float speed){
    
    for(int i = 1; i < u_n.get_mesh()->x_size(); ++i )
    {
        float res = u_n[i] - (speed * (u_n.get_mesh()->get_dt()/u_n.get_mesh()->get_dx())) * (u_n[i] - u_n[i-1]);
        u_np1.set_I_elem(i, res);
    }
    return u_np1;
}