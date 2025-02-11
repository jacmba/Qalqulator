#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include "operation.h"

class OperationFactory
{
private:
    OperationFactory();
    static OperationFactory instance;
public:

    static OperationFactory getInstance();
    IOperation* getOperation(OperationType op);
};

#endif // OPERATIONFACTORY_H
