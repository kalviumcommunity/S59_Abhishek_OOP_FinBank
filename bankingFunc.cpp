#include "banking.h"

Account::Account(int accNum, double initialBalance)
    : accountNumber(accNum), balance(initialBalance) {}

void Account::deposit(double amount) {
    balance += amount;
}

void Account::withdraw(double amount) {
    if (amount > balance) {
        cout << "Insufficient funds." << endl;
    } else {
        balance -= amount;
    }
}

void Account::displayAccountInfo() const {
    cout << "Account Number: " << accountNumber << ", Current Balance: " << balance << endl;
}

double Account::getBalance() const {
    return balance;
}

int Account::getAccountNumber() const {
    return accountNumber;
}

InterestBearingAccount::InterestBearingAccount(int accNum, double initialBalance)
    : Account(accNum, initialBalance) {}

SavingsAccount::SavingsAccount(int accNum, double initialBalance, double rate)
    : InterestBearingAccount(accNum, initialBalance), interestRate(rate) {}

double SavingsAccount::calculateInterest() const {
    return balance * interestRate;
}

void SavingsAccount::applyInterest() {
    balance += calculateInterest();
}

void SavingsAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
}

void TransactionProcessor::deposit(Account* account, double amount) {
    account->deposit(amount);
    StatisticsTracker::incrementDeposits();
    cout << "Deposit successful. New balance: " << account->getBalance() << endl;
}

void TransactionProcessor::withdraw(Account* account, double amount) {
    account->withdraw(amount);
    StatisticsTracker::incrementWithdrawals();
    cout << "Transaction complete. Remaining balance: " << account->getBalance() << endl;
}

void TransactionProcessor::displayBalance(const Account* account) const {
    account->displayAccountInfo();
}

int StatisticsTracker::totalDeposits = 0;
int StatisticsTracker::totalWithdrawals = 0;

void StatisticsTracker::incrementDeposits() {
    totalDeposits++;
}

void StatisticsTracker::incrementWithdrawals() {
    totalWithdrawals++;
}

void StatisticsTracker::displayStats(int option) {
    if (option == 1) {
        cout << "Total Deposits: " << totalDeposits << endl;
    } else if (option == 2) {
        cout << "Total Withdrawals: " << totalWithdrawals << endl;
    }
}
