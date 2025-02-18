#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <iostream>
#include <string>

#define String  std::string

class Account {
    private:

    String  accountNumber;
    double balance;

    public:

    Account(String  accountNumber, double balance) {
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    String  getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void debit(double amount) {
        balance -= amount;
    }

    void credit(double amount) {
        balance += amount;
    }
};

#endif // ACCOUNT_HPP

