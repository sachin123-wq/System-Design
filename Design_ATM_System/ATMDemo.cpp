#include <iostream>

#include "Card.hpp"
#include "ATM.hpp"

int main(){

	BankingService* bankingService = new BankingService();
	CashDispenser* cashDispenser = new CashDispenser(10000);
	ATM *atm = new ATM(*bankingService, *cashDispenser);


	bankingService->createAccount("1234567890", 500);
	bankingService->createAccount("9876543210", 1000);

	 // Perform ATM operations
	Card* card = new Card("1234567890", "1234");
	atm->authenticateUser(card->getCardNumber());

	double balance = atm->checkBalance("1234567890");
	std::cout << "Account Balance: " << balance << std::endl;

	atm->withdrawCash("1234567890",400);
	atm->withdrawCash("1234567800",400);

	atm->depositCash("9876543210", 1000);

	balance = atm->checkBalance("9876543210");
	std::cout << "For Account Number: 9876543210 " << "Updated Account Balance: " << balance << std::endl;


	double balance1 = atm->checkBalance("1234567890");
	std::cout << "For Account Number: 1234567890 " << "Updated Account Balance: " << balance1 << std::endl;

	atm->withdrawCash("1234567890",200);
}