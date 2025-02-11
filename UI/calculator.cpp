#include "calculator.h"

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

void Calculator::clearOperation()
{
    if (operation != nullptr) {
        delete operation;
    }
}
