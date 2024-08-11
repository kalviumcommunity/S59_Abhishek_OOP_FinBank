#include "bankingFunc.cpp"
#include <iostream>

int main() {
    const int NUM_ACCOUNTS = 3;

    Account accounts[NUM_ACCOUNTS] = {
        Account(1001, 500.0),
        Account(1002, 1000.0),
        Account(1003, 1500.0)
    };
    ATM atm;

    for (int i = 0; i < NUM_ACCOUNTS; ++i) {
        cout << "\nOperating on Account " << (i + 1) << " (Account Number: " << accounts[i].getAccountNumber() << ")\n";

        atm.deposit(accounts[i], 100.0);

        atm.withdraw(accounts[i], 50.0);

        atm.displayBalance(accounts[i]);
    }
    return 0;
}
