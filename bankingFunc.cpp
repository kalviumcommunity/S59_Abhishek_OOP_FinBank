#include "banking.h"
#include <iostream>
using namespace std;

int ATM::totalDeposits = 0;
int ATM::totalWithdrawals = 0;

Account::Account() {
    this->accountNumber = 0;
    this->balance = 0.0;
    cout << "Account created with default values." << endl;
}

Account::Account(int accNum, double initialBalance) {
    this->accountNumber = accNum;
    this->balance = initialBalance;
    cout << "Account created with Account Number: " << accNum << " and Initial Balance: " << initialBalance << endl;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::setBalance(double newBalance) {
    this->balance = newBalance;
}

int Account::getAccountNumber() const {
    return this->accountNumber;
}
ATM::ATM() {
    this->transactionLimit = 5000.0;
    cout << "ATM created with default transaction limit of " << transactionLimit << endl;
}
ATM::ATM(double limit) {
    this->transactionLimit = limit;
    cout << "ATM created with transaction limit of " << limit << endl;
}

double ATM::getTransactionLimit() const {
    return transactionLimit;
}

void ATM::setTransactionLimit(double newLimit) {
    transactionLimit = newLimit;
}
void ATM::deposit(Account* account, double amount) {
    if (amount > transactionLimit) {
        cout << "Transaction exceeds the limit of " << transactionLimit << endl;
        return;
    }
    double newBalance = account->getBalance() + amount;
    account->setBalance(newBalance);
    totalDeposits++;
    cout << "Deposit successful. New balance: " << newBalance << endl;
}
void ATM::withdraw(Account* account, double amount) {
    double currentBalance = account->getBalance();
    if (amount > transactionLimit) {
        cout << "Transaction exceeds the limit of " << transactionLimit << endl;
        return;
    }
    if (amount > currentBalance) {
        cout << "Insufficient funds." << endl;
    } else {
        double newBalance = currentBalance - amount;
        account->setBalance(newBalance);
        totalWithdrawals++;
        cout << "Withdrawal successful. Remaining balance: " << newBalance << endl;
    }
}
void ATM::displayBalance(const Account* account) const {
    cout << "Account Number: " << account->getAccountNumber() << endl;
    cout << "Current Balance: " << account->getBalance() << endl;
}
void ATM::displayStats(int option) {
    if (option == 1) {
        cout << "Total Deposits: " << totalDeposits << endl;
    } else if (option == 2) {
        cout << "Total Withdrawals: " << totalWithdrawals << endl;
    }
}

ATM::~ATM() {
    cout << "ATM object is being destroyed." << endl;
}

Account::~Account() {
    cout << "Account with Account Number " << this->accountNumber << " is being destroyed." << endl;
}