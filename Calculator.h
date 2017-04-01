/**
  * @brief Assignment 9 part B
  * @author Alexander Molodyh
  */

#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
public:

    /**
     * @brief Calculator Sets up the numbers and the operator type
     */
    Calculator();
    enum opType
    {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE,
        SQRT,
        NONE    //no stored operation
    };

    int temp = 0;

    /**
     * @brief store Stores a value to num2
     * @param value An int value
     */
    void store(double value);

    /**
     * @brief handleOperation Processes any existing operation, stores new operation
     * @param newOperation An operator type
     * @return Result of existing operation (num1)
     */
    double handleOperation(opType newOperation);

    /**
     * @brief equalsPressed Processes existing operation, sores result to num1 and returns it
     * @return A double value that represents the calculated total
     */
    double equalsPressed();

    /**
     * @brief clear Clear all state
     */
    void clear();

private:
    double num1;
    double num2;
    opType oper;
};

#endif // CALCULATOR_H
