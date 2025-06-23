/*
   +-----------------+
   |  PaymentStrategy|<-- Interface
   +-----------------+
   | + pay(amount)   |
   +-----------------+
         ▲
         |
   +-----------+     +----------------+     +----------------+
   | UpiPayment|     | CreditCardPayment |   | WalletPayment |
   +-----------+     +----------------+     +----------------+

   +----------------+
   | PaymentContext |
   +----------------+
   | - strategy     |
   | + setStrategy()|
   | + payAmount()  |
   +----------------+

*/

#include <iostream>
using namespace std;

// Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(double amount) = 0;
    virtual ~PaymentStrategy() = default;
};

// Concrete Strategies

class CreditCardPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using Credit Card.\n";
    }
};

class UpiPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using UPI.\n";
    }
};

class WalletPayment : public PaymentStrategy {
public:
    void pay(double amount) override {
        cout << "Paid ₹" << amount << " using Wallet.\n";
    }
};

// Context Class

class PaymentContext {
private:
    PaymentStrategy* strategy;

public:
    void setStrategy(PaymentStrategy* strat) {
        strategy = strat;
    }

    void payAmount(double amount) {
        if (strategy)
            strategy->pay(amount);
        else
            cout << "No payment method selected!\n";
    }
};


int main() {
    PaymentContext context;

    CreditCardPayment card;
    UpiPayment upi;
    WalletPayment wallet;

    context.setStrategy(&card);
    context.payAmount(500);

    context.setStrategy(&upi);
    context.payAmount(250);

    context.setStrategy(&wallet);
    context.payAmount(100);

    return 0;
}
