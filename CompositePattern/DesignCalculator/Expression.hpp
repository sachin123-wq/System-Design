// Create concreate class for Expression and implement evaluate method
#include "ArithmeticExpression.hpp"
#include "Operation.hpp"
#include <stdexcept>

class Expression : public ArithmeticExpression {
private:
    ArithmeticExpression *leftExpression;
    ArithmeticExpression *rightExpression;
    Operation operation;
public:
    Expression(ArithmeticExpression *leftExpression, ArithmeticExpression *rightExpression, Operation operation) : leftExpression(leftExpression), rightExpression(rightExpression), operation(operation) {}
    double evaluate() override {
        double leftNumber, rightNumber;
        switch(operation) {
            case Operation::ADDITION:
                return leftExpression->evaluate() + rightExpression->evaluate();
            case Operation::SUBTRACTION:
                return leftExpression->evaluate() - rightExpression->evaluate();
            case Operation::MULTIPLICATION:
                return leftExpression->evaluate() * rightExpression->evaluate();
            case Operation::DIVISION:
                leftNumber = leftExpression->evaluate();
                rightNumber = rightExpression->evaluate();
                if(rightNumber == 0) {
                    throw std::runtime_error("Math error: Attempted to divide by Zero\n");
                }
                return leftNumber / rightNumber;
            default:
                throw std::runtime_error("Math error: Invalid operation\n");
        }
    }
    ~Expression() = default;
};