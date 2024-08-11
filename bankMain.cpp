#include "bankingFunc.cpp"
#include <iostream>

int main() {

    Account account1(1001, 50000.0);
    cout<<"Account created successfully"<<endl;

    ATM atm;

    atm.deposit(account1, 200.0);
    atm.withdraw(account1, 100.0);
    atm.displayBalance(account1);
    atm.withdraw(account1, 700.0); 

    return 0;
}
