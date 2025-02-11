#include <QtTest>
#include <operationfactory.h>

class TestOperations : public QObject
{
    Q_OBJECT

public:
    TestOperations();
    ~TestOperations();

private slots:
    void test_sum();
    void test_subtract();
    void test_multiply();
    void test_divide();
    void test_power();
};

TestOperations::TestOperations() {}

TestOperations::~TestOperations() {
}

void TestOperations::test_sum()
{
    OperationFactory factory = OperationFactory::getInstance();
    IOperation *operation = factory.getOperation(ADD);
    QVERIFY2(operation != nullptr, "ADD operation should not be null");

    double result = operation->exec(1, 3);
    delete operation;
    QCOMPARE(result, 4);
}

void TestOperations::test_subtract()
{
    OperationFactory factory = OperationFactory::getInstance();
    IOperation *operation = factory.getOperation(SUBTRACT);
    QVERIFY2(operation != nullptr, "Subtract operation should not be null");

    double result = operation->exec(7, 5);
    delete operation;
    QCOMPARE(result, 2);
}

void TestOperations::test_multiply()
{
    OperationFactory factory = OperationFactory::getInstance();
    IOperation *operation = factory.getOperation(MULTIPLY);
    QVERIFY2(operation != nullptr, "Multiply operation should not be null");

    double result = operation->exec(2, 3);
    delete operation;
    QCOMPARE(result, 6);
}

void TestOperations::test_divide()
{
    OperationFactory factory = OperationFactory::getInstance();
    IOperation *operation = factory.getOperation(DIVIDE);
    QVERIFY2(operation != nullptr, "Divide operation should not be null");

    double result = operation->exec(10, 5);
    delete operation;
    QCOMPARE(result, 2);
}

void TestOperations::test_power()
{
    OperationFactory factory = OperationFactory::getInstance();
    IOperation *operation = factory.getOperation(POWER);
    QVERIFY2(operation != nullptr, "Power operation should not be null");

    double result = operation->exec(2, 3);
    delete operation;
    QCOMPARE(result, 8);
}

QTEST_APPLESS_MAIN(TestOperations)

#include "tst_testoperations.moc"
