#include "Lax_Wendroff.h"
#include <cmath>

/* Computes the element at time n plus 1 following the Lax-Wendroff Model*/
Variable Lax_Wendroff::update(Variable &u_n, Variable &u_np1, float speed){
    
    for(int i = 1; i < u_n.get_mesh()->x_size(); ++i )
    {
        //Deltas
        float dx = u_n.get_mesh()->get_dx();
        float dt = u_n.get_mesh()->get_dt();

        float order_one = speed * (dt/ (2*dx) ) * (u_n[i+1] - u_n[i-1]);
        float order_two = pow(speed, 2) * (pow(dt, 2)/ (2*pow(dx, 2))) * (u_n[i+1] - 2*u_n[i] + u_n[i-1]);

        float res = u_n[i] - order_one + order_two;
        u_np1.set_I_elem(i, res);
    }
    return u_np1;
}