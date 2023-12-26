#ifndef UPWIND_H_
#define UPWIND_H_

#include "Variable.h"
#include "IMesh.h"

struct Upwind{
    static Variable update(Variable &u_n, Variable &u_np1, float speed);
};

#endif