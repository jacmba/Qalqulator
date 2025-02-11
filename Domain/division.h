#ifndef DIVISION_H
#define DIVISION_H

#include "operation.h"

class Division : public IOperation
{
public:
    double exec(double op1, double op2);
};

#endif // DIVISION_H
