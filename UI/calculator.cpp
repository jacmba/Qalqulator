#include "calculator.h"
#include <cmath>

Calculator::Calculator() {
    operation = nullptr;
}

Calculator::~Calculator()
{
    clearOperation();
}

void Calculator::setOperation(OperationType opType, const double &op)
{
    clearOperation();

    OperationFactory factory = OperationFactory::getInstance();
    operation = factory.getOperation(opType);
    operand = op;
}

double Calculator::calculate(double op)
{
    if (operation == nullptr) {
        return 0;
    }

    return operation->exec(operand, op);
}

double Calculator::calculateSquare(double op)
{
    return op * op;
}

double Calculator::calculateSqrt(double op)
{
    return std::sqrt(op);
}

void Calculator::clearOperation()
{
    if (operation != nullptr) {
        delete operation;
    }
}
