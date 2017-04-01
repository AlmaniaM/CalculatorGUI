#include "Calculator.h"
#include <stdexcept>
#include <cmath>
using namespace std;

Calculator::Calculator()
{
    num1 = 0;
    num2 = 0;
    oper = NONE;
}

void Calculator::store(double value) {
    num2 = value;
}

double Calculator::handleOperation(Calculator::opType newOperation)
{
    if(oper == NONE)
    {
        num1 = num2;
        oper = newOperation;
        return num1;
    }
    else if(newOperation == SQRT)
    {
        num2 = sqrt(num2);
        return num2;
    }
    else if(num1 > 0)
    {
        if(oper == ADD)
        {
            num1 = num1 + num2;
            oper = newOperation;
            return num1;
        }
        else if(oper == SUBTRACT)
        {
            num1 = num1 - num2;
            oper = newOperation;
            return num1;
        }
        else if(oper == MULTIPLY)
        {
            num1 = num1 * num2;
            oper = newOperation;
            return num1;
        }
        else if(oper == DIVIDE)
        {
            num1 = num1 / num2;
            oper = newOperation;
            return num1;
        }
    }
}

double Calculator::equalsPressed()
{
    return handleOperation(oper);
    oper = NONE;
}

void Calculator::clear()
{
    num1 = 0;
    num2 = 0;
    oper = NONE;
}
