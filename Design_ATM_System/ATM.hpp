#include <ctime>
#include <iomanip>
#include <atomic>
#include <sstream>

#include "CashDispenser.hpp"
#include "BankingService.hpp"
#include "WithdrawalTransaction.hpp"
#include "DepositTransaction.hpp"


class ATM{
private:
	BankingService &bankingService;
	CashDispenser &cashDispenser;
	static std::atomic<long> transactionCounter;

public:

	ATM(BankingService& bankingService, CashDispenser& cashDispenser) 
		: bankingService(bankingService), cashDispenser(cashDispenser) {}
	
	void authenticateUser(const String& cardNumber) {
		// Authentication logic using card and PIN
		std::cout << "Authenticating user with card: " << cardNumber << std::endl;
	}

	double checkBalance(const String& accountNumber) {
		auto account = bankingService.getAccount(accountNumber);
		if(account){
			return account->getBalance();
		}
		else{
			std::cerr << "Account not found!" << std::endl;
			return 0.0;
		}
	}

	void withdrawCash(const String& accountNumber, double amount){
		auto account = bankingService.getAccount(accountNumber);
		if(!account){
			std::cerr << "Account not found!" << std::endl;
			return;
		}
		if(account->getBalance() < amount){
			std::cerr << "Account = " << account->getAccountNumber() << " does not contain enough cash.\n" 
			<< "Current Balance of the account is  = " << account->getBalance() 
			<< "\nAnd requested amount is = " << amount
			<< std::endl; 
			return;
		}
		auto transaction = std::make_shared<WithdrawalTransaction>(generateTransactionId(), account, amount);
		bankingService.processTransaction(transaction);
		cashDispenser.dispenseCash(static_cast<int>(amount));
	}

	void depositCash(const String& accountNumber, double amount){
		auto account = bankingService.getAccount(accountNumber);
		if(!account){
			std::cerr << "Account not found!" << std::endl;
			return;
		}

		auto transaction = std::make_shared<DepositTransaction>(generateTransactionId(), account, amount);
		bankingService.processTransaction(transaction);
	}
	
private:

	String generateTransactionId() {
		long transactionNumber = ++transactionCounter;
		auto t = std::time(nullptr);
		auto tm = *std::localtime(&t);

		std::ostringstream oss;
		oss << "TXN"
			<< std::put_time(&tm, "%Y%m%d%H%M%S")
			<< std::setw(10) << std::setfill('0') << transactionNumber;
		return oss.str();
	}
};

// Initialize the static variable
std::atomic<long> ATM::transactionCounter{0};
