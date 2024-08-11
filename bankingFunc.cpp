#include "banking.h"
#include <iostream>
using namespace std;

Account::Account(int accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance) {}

double Account::getBalance() const {
    return balance;
}

void Account::setBalance(double newBalance) {
    balance = newBalance;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

void ATM::deposit(Account &account, double amount) {
    double newBalance = account.getBalance() + amount;
    account.setBalance(newBalance);
    cout << "Deposit successful. New balance: " << newBalance << endl;
}

void ATM::withdraw(Account &account, double amount) {
    double currentBalance = account.getBalance();
    if (amount > currentBalance) {
        cout << "Insufficient funds." << endl;
    } else {
        double newBalance = currentBalance - amount;
        account.setBalance(newBalance);
        cout << "Withdrawal successful. Remaining balance: " << newBalance << endl;
    }
}
void ATM::displayBalance(const Account &account) const {
    cout << "Account Number: " << account.getAccountNumber() << endl;
    cout << "Current Balance: " << account.getBalance() << endl;
}