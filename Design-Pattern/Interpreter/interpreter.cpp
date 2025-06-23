#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <stack>

using namespace std;


// Abstract Expression
class Expression {
public:
    virtual ~Expression() = default;
    virtual double interpret() const = 0;
};

// Terminal Expression
class Number : public Expression {
double value;
public:
    Number(const double val) : value(val) {}
    double interpret() const override {
        return value;
    }
};

// Non-terminal Expression: Addition
class Addition : public Expression {
    shared_ptr<Expression> left;
    shared_ptr<Expression> right;
public:
    Addition(shared_ptr<Expression> l, shared_ptr<Expression> r) : left(l), right(r) {}
    double interpret() const override {
        return left->interpret() + right->interpret();
    }
};

// Non-terminal Expression: Subtraction
class Subtraction : public Expression {
    shared_ptr<Expression> left;
    shared_ptr<Expression> right;
public:
    Subtraction(shared_ptr<Expression> l, shared_ptr<Expression> r) : left(l), right(r) {}
    double interpret() const override {
        return left->interpret() - right->interpret();
    }
};

// Expression Parser

unique_ptr <Expression> parse(string input){
    istringstream stream(input);
    stack<unique_ptr<Expression>> exprStack;

    string token;
    while (stream >> token) {
        if (isdigit(token[0])){
            exprStack.push(make_unique<Number>(stod(token)));
        } else if (token == "+" || token == "-") {
            string next;
            stream >> next;
            auto right = make_unique<Number>(stod(next));
            auto left = std::move(exprStack.top());
            exprStack.pop();

            if (token == "+") {
                exprStack.push(make_unique<Addition>(std::move(left), std::move(right)));
            } else {
                exprStack.push(make_unique<Subtraction>(std::move(left), std::move(right)));
            }
        }
    }
    return std::move(exprStack.top());
}

int main() {
    string expression = "5.0 + 3.1 + 4.56 - 2.9";
    auto exprTree = parse(expression);
    cout << "Result of '" << expression << "' = " << exprTree->interpret() << endl;
    return 0;
}

