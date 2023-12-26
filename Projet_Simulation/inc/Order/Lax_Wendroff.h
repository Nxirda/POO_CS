#ifndef LAX_WENDROFF_H_
#define LAX_WENDROFF_H_

#include "Variable.h"
#include "IMesh.h"

struct Lax_Wendroff{
    static Variable update(Variable &u_n, Variable &u_np1, float speed);
};

#endif