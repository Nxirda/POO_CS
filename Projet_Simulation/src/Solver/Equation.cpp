#include <iostream>
#include <execution>
#include <algorithm>
#include <cmath>

#include "Equation.h"

/* Constructor */
Equation::Equation()
{
    this->speed = 1;
}

/* Destructor */
Equation::~Equation(){};

/* Get the speed */
float Equation::get_speed()
{
    return this->speed;
}

/* Set the speed */
void Equation::set_speed(float a)
{
    this->speed = a;
}