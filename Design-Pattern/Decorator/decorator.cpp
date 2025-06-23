#include <iostream>
#include <memory>
#include <string>
using namespace std;

// Base interface
class Pizza {
public:
    virtual string getDescription() const = 0;
    virtual double getCost() const = 0;
    virtual ~Pizza() = default;
};

// Concrete component
class MargheritaPizza : public Pizza {
public:
    string getDescription() const override {
        return "Margherita Pizza";
    }
    double getCost() const override {
        return 5.0;
    }
};

// Base Decorator
class ToppingDecorator : public Pizza {
protected:
    shared_ptr<Pizza> pizza;
public:
    ToppingDecorator(shared_ptr<Pizza> p) : pizza(p) {}
};

// Concrete Decorators
class CheeseDecorator : public ToppingDecorator {
public:
    CheeseDecorator(shared_ptr<Pizza> p) : ToppingDecorator(p) {}
    string getDescription() const override {
        return pizza->getDescription() + ", Cheese";
    }
    double getCost() const override {
        return pizza->getCost() + 1.5;
    }
};

class OliveDecorator : public ToppingDecorator {
public:
    OliveDecorator(shared_ptr<Pizza> p) : ToppingDecorator(p) {}
    string getDescription() const override {
        return pizza->getDescription() + ", Olives";
    }
    double getCost() const override {
        return pizza->getCost() + 1.0;
    }
};


int main() {
    shared_ptr<Pizza> pizza = make_shared<MargheritaPizza>();

    pizza = make_shared<CheeseDecorator>(pizza);
    pizza = make_shared<OliveDecorator>(pizza);

    cout << "Order: " << pizza->getDescription() << endl;
    cout << "Total Cost: $" << pizza->getCost() << endl;

    return 0;
}

