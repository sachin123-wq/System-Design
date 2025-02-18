#include <iostream>
#include <unordered_map>
#include <memory>
#include <mutex>

#include "Transaction.hpp"

class BankingService{
private:
	std::unordered_map<String, std::shared_ptr<Account>> accounts;
	std::mutex mtx;

public:
	BankingService() = default;
	// Delete copy constructor and assignment operator
    BankingService(const BankingService&) = delete;

	void createAccount(String accountNumber, double initialBalance){
		std::lock_guard<std::mutex> lock(mtx);
		accounts[accountNumber] = std::make_shared<Account>(accountNumber, initialBalance);
	}

	std::shared_ptr<Account> getAccount(const String &accountNumber){
		std::lock_guard<std::mutex> lock(mtx);
		auto it = accounts.find(accountNumber);
		return (it != accounts.end()) ? it->second : nullptr;
	}

	void processTransaction(std::shared_ptr<Transaction> transaction){
		transaction->execute();
	}
};