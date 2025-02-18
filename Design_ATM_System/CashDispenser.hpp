#include <iostream>
#include <mutex>
#include <stdexcept>

class CashDispenser {
private:
    int cashAvailable;
    std::mutex mtx; // For synchronization

public:

    // Constructor
    CashDispenser(int initialCash) : cashAvailable(initialCash) {}

    // Synchronized method to dispense cash

    void dispenseCash(int amount){
        std::lock_guard<std::mutex> lock(mtx);

        if(amount > cashAvailable){
            throw std::invalid_argument("Insufficient cash available in the ATM.");
        }

        cashAvailable -= amount;
        std::cout << "Cash dispensed: " << amount << std::endl;
    }
};