#include "operationfactory.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "division.h"
#include "power.h"

OperationFactory::OperationFactory() {}

OperationFactory OperationFactory::getInstance()
{
    return instance;
}

IOperation* OperationFactory::getOperation(OperationType op)
{
    switch(op) {
    case ADD:
        return new Addition();
    case SUBTRACT:
        return new Subtraction();
    case MULTIPLY:
        return new Multiplication();
    case DIVIDE:
        return new Division();
    case POWER:
        return new Power();
    default:
        return nullptr;
    }
}
