#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <operationfactory.h>

class Calculator
{
public:
    Calculator();
    ~Calculator();

    void setOperation(OperationType opType, const double &op);
    double calculate(double op);
    double calculateSquare(double op);
    double calculateSqrt(double op);

private:
    IOperation *operation;
    double operand;

    void clearOperation();
};

#endif // CALCULATOR_H
