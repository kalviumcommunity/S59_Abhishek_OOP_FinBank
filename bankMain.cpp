#include "bankingFunc.cpp"
#include <iostream>

int main()
{
    Account *account = new Account(1001, 5000.0);
    ATM atm;

    atm.displayBalance(account);
    
    atm.deposit(account, 100.0);

    atm.withdraw(account, 50.0);

    atm.withdraw(account, 500.0);

    atm.displayBalance(account);

    int option;
    atm.displayStats(option);
    delete account;
    
    return 0;
}
