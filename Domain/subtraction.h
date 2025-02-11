#ifndef SUBTRACTION_H
#define SUBTRACTION_H

#include "operation.h"

class Subtraction : public IOperation
{
public:
    double exec(double op1, double op2);
};

#endif // SUBTRACTION_H
