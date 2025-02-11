#ifndef ADDITION_H
#define ADDITION_H

#include "operation.h"

class Addition : public IOperation
{
public:
    double exec(double op1, double op2);
};

#endif // ADDITION_H
