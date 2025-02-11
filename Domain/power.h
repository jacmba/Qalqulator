#ifndef POWER_H
#define POWER_H

#include "operation.h"

class Power : public IOperation
{
    double exec(double op1, double op2);
};

#endif // POWER_H
