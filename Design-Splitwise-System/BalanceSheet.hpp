#include <iostream>
#include <unordered_map>
#include <cmath>
#include <iomanip>

class BalanceSheet {
private:
    // Store balances as a map of maps
    std::unordered_map<std::string, std::unordered_map<std::string, double>> balances;

public:
    void addTransaction(std::string paidBy, std::string paidTo, double amount) {
        balances[paidBy][paidTo] += amount;
        balances[paidTo][paidBy] -= amount;
    }

    void showBalances() {
        bool hasBalance = false;
        for (auto& p : balances) {
            for (auto& q : p.second) {
                if (q.second > 0.0) {
                    hasBalance = true;
                    std::cout << q.first << " owes " << p.first << ": " << std::fixed << std::setprecision(2) << q.second << std::endl;
                }
            }
        }
        if (!hasBalance) std::cout << "No balances" << std::endl;
    }

    void showBalanceForUser(std::string userId) {
        bool hasBalance = false;
        for (auto& p : balances[userId]) {
            if (p.second < 0.0) {
                hasBalance = true;
                std::cout << userId << " owes " << p.first << ": " << std::fixed << std::setprecision(2) << fabs(p.second) << std::endl;
            } else if (p.second > 0.0) {
                hasBalance = true;
                std::cout << p.first << " owes " << userId << ": " << std::fixed << std::setprecision(2) << p.second << std::endl;
            }
        }
        if (!hasBalance) std::cout << "No balances" << std::endl;
    }
};
