// Create abstract class for ArithmeticExpression

#ifndef ARITHMETICEXPRESSION_HPP
#define ARITHMETICEXPRESSION_HPP

class ArithmeticExpression {
public:
    virtual double evaluate() = 0;
    ~ArithmeticExpression() = default;
};

#endif // ARITHMETICEXPRESSION_HPP