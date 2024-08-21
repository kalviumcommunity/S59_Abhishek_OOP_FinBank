#include "bankingFunc.cpp"
#include <iostream>

int main()
{

    Account *account = new Account(1001, 500.0);
    ATM atm;

    atm.displayBalance(account);
    
    atm.deposit(account, 100.0);

    atm.withdraw(account, 50.0);

    atm.displayBalance(account);
    delete account;
    
    return 0;
}
