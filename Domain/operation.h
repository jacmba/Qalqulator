#ifndef OPERATION_H
#define OPERATION_H

enum OperationType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER
};

class IOperation
{
public:
    virtual ~IOperation() = default;

    virtual double exec(double op1, double op2) = 0;
};

#endif // OPERATION_H
