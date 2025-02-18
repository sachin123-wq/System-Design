

#include "Transaction.hpp"


class DepositTransaction : public Transaction {

    public:
    DepositTransaction(String  transactionId, std::shared_ptr<Account> account, double amount) : Transaction(transactionId, account, amount){}

    void execute() {
        account->credit(amount);
    }
};