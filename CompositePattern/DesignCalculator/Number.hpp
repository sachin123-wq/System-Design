// Create Number class that inherits from ArithmeticExpression
#include "ArithmeticExpression.hpp"

class Number : public ArithmeticExpression {
private:
    double value;
public: 
    Number(double value) : value(value) {}
    double evaluate() override {
        return value;
    }
    ~Number() = default;
};
