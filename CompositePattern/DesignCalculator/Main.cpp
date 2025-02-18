#include "iostream"
#include "Expression.hpp"
#include "Number.hpp"
#include "Operation.hpp"


int main(){

    try{
    // Evaluate expression (3 * (20 / 5))

        ArithmeticExpression *expression = new Expression(new Number(3),
                                        new Expression(new Number(20), new Number(5), Operation::DIVISION), 
                                        Operation::MULTIPLICATION);
        std::cout << expression->evaluate() << std::endl;

        // Evaluate expression (3 * (20 * 5) + 10)
        ArithmeticExpression *expression2 = new Expression(new Expression(new Number(3), 
                                            new Expression(new Number(20), new Number(5), Operation::MULTIPLICATION), 
                                            Operation::MULTIPLICATION), new Number(10), Operation::ADDITION);
        std::cout << expression2->evaluate() << std::endl;

        // Evaluate expression (3 * (20 * 5) / 0)
        ArithmeticExpression *expression3 = new Expression(new Expression(new Number(3), 
                                            new Expression(new Number(20), new Number(5), Operation::MULTIPLICATION), 
                                            Operation::MULTIPLICATION), new Number(0), Operation::DIVISION);
        std::cout << expression3->evaluate() << std::endl;
    }
    catch (const std::runtime_error e){
        std::cout << e.what() << std::endl;
    }   
}