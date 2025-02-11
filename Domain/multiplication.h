#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H

#include "operation.h"

class Multiplication : public IOperation
{
public:
    double exec(double op1, double op2);
};

#endif // MULTIPLICATION_H
