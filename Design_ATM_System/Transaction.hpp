#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include <memory>
#include "Account.hpp"

class Transaction {

	protected:
	String  transactionId;
	std::shared_ptr<Account> account;
	double amount;

	public:

	// Transaction(String  transactionId, Account account, double amount){
	// 	this->transactionId = transactionId;
	// 	this->account = account;
	// 	this->amount = amount;
	// }

	/*
	Why below code works but not above one:
		The initializer list initializes transactionId, account, and amount before the constructor's body is executed.
		Without this, the compiler tries to call the default constructor for account, which doesn't exist, causing the error.
	*/

	Transaction(const std::string& transactionId, const std::shared_ptr<Account> account, double amount): 
		transactionId(transactionId), account(account), amount(amount) {} // Use initializer list

	virtual void execute() = 0;
};

#endif // TRANSACTION_HPP
