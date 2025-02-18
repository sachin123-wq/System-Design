
#include "DepositTransaction.hpp"

int main(){
    Account account1("34567",1000);
    account1.credit(500);
    std::cout<<"For account number = " << account1.getAccountNumber() << " , we have total balance  = " << account1.getBalance() << std::endl;

}