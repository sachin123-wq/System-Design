#include "ExpenseManager.hpp"
#include <sstream>
#include <stdexcept>

// Overload the >> operator for ExpenseType
std::istream &operator>>(std::istream &in, ExpenseType &type) {
	std::string value;
	in >> value;
	if (value == "EQUAL") {
		type = ExpenseType::EQUAL;
	} else if (value == "EXACT") {
		type = ExpenseType::EXACT;
	} else if (value == "PERCENT") {
		type = ExpenseType::PERCENT;
	} else {
		throw std::invalid_argument("Invalid ExpenseType");
	}
	return in;
}

void parseCommand(ExpenseManager &manager, const std::string &input) {
	std::stringstream ss(input);
	std::string command;
	ss >> command;

	if (command == "SHOW") {
		std::string userId;
		if (ss >> userId) {
			manager.showUserBalance(userId);
		} else {
			manager.showBalances();
		}
	} else if (command == "EXPENSE") {
		std::string paidBy;
		int numUsers;
		double amount;
		ss >> paidBy >> amount >> numUsers;
		std::vector<std::string> usersInTxn(numUsers);
		for (int i = 0; i < numUsers; ++i) ss >> usersInTxn[i];
		ExpenseType type;
		ss >> type;

		std::vector<double> values;
		double v;
		while (ss >> v) values.push_back(v);

		manager.addExpense(paidBy, amount, usersInTxn, type, values);
	}
}

int main() {
	ExpenseManager manager;
	manager.addUser("u1", "User1", "user1@mail.com", "9999999991");
	manager.addUser("u2", "User2", "user2@mail.com", "9999999992");
	manager.addUser("u3", "User3", "user3@mail.com", "9999999993");
	manager.addUser("u4", "User4", "user4@mail.com", "9999999994");

	std::vector<std::string> inputs = {
		"SHOW",
		"SHOW u1",
		"EXPENSE u1 1000 4 u1 u2 u3 u4 EQUAL",
		"SHOW u4",
		"SHOW u1",
		"EXPENSE u1 1250 2 u2 u3 EXACT 370 880",
		"SHOW",
		"EXPENSE u4 1200 4 u1 u2 u3 u4 PERCENT 40 20 20 20",
		"SHOW u1",
		"SHOW"
	};

	for (auto &cmd : inputs) {
        std::cout << "Command: " << cmd << std::endl;
		parseCommand(manager, cmd);
        std::cout << "----------------------------------------" << std::endl;
	}

	return 0;
}
