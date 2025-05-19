#include "BalanceSheet.hpp"
#include "User.hpp"
#include "ExpenseType.hpp"
#include <vector>

class ExpenseManager {
private:
	std::unordered_map<std::string, User*> users;
	BalanceSheet balanceSheet;

public:
	void addUser(std::string id, std::string name, std::string email, std::string mobile) {
		users[id] = new User(id, name, email, mobile);
	}

	void showBalances() {
		balanceSheet.showBalances();
	}

	void showUserBalance(std::string userId) {
		balanceSheet.showBalanceForUser(userId);
	}

	void addExpense(std::string paidBy, double amount, std::vector<std::string> &usersInTxn, ExpenseType type, std::vector<double> &values) {
		int n = usersInTxn.size();
		std::vector<double> share(n, 0.0);

		if (type == ExpenseType::EQUAL) {
			double each = round((amount / n) * 100.0) / 100.0;
			double total = each * n;
			share[0] = amount - (each * (n - 1));  // adjust for rounding
			for (int i = 1; i < n; ++i) share[i] = each;
		} else if (type == ExpenseType::EXACT) {
			double sum = 0;
			for (auto v : values) sum += v;
			if (round(sum * 100) / 100.0 != round(amount * 100) / 100.0) {
				std::cout << "Exact shares do not sum to total." << std::endl;
				return;
			}
			share = values;
		} else if (type == ExpenseType::PERCENT) {
			double sum = 0;
			for (auto v : values) sum += v;
			if (round(sum * 100) / 100.0 != 100.0) {
				std::cout << "Percentage shares do not sum to 100%." << std::endl;
				return;
			}
			for (int i = 0; i < n; ++i)
				share[i] = round((amount * values[i] / 100.0) * 100.0) / 100.0;
		}

		for (int i = 0; i < n; ++i) {
			if (usersInTxn[i] != paidBy) {
				balanceSheet.addTransaction(paidBy, usersInTxn[i], share[i]);
			}
		}
	}
};
