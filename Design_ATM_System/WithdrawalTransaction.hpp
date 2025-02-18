#include "Transaction.hpp"

class WithdrawalTransaction : public Transaction {

    public:
    WithdrawalTransaction(String  transactionId, std::shared_ptr<Account> account, double amount) : Transaction(transactionId, account, amount){}

    void execute() {
        account->debit(amount);
    }
};

