#include "banking.h"

Account::Account(int accNum, double initialBalance) {
    this->accountNumber = accNum;
    this->balance = initialBalance;
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

void Account::displayAccountInfo() const {
    cout << "Account Number: " << accountNumber << ", Current Balance: " << balance << endl;
}

SavingsAccount::SavingsAccount(int accNum, double initialBalance, double rate)
    : Account(accNum, initialBalance), interestRate(rate) {}

SavingsAccount::SavingsAccount()
    : Account(0, 0.0), interestRate(0.05) {}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}

void SavingsAccount::applyInterest() {
    double interest = calculateInterest();
    setBalance(getBalance() + interest);
}

void SavingsAccount::displayAccountInfo() const {
    Account::displayAccountInfo();
    cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
}

void TransactionProcessor::deposit(Account* account, double amount) {
    double newBalance = account->getBalance() + amount;
    account->setBalance(newBalance);
    StatisticsTracker::incrementDeposits();
    cout << "Deposit successful. New balance: " << newBalance << endl;
}

void TransactionProcessor::withdraw(Account* account, double amount) {
    double currentBalance = account->getBalance();
    if (amount > currentBalance) {
        cout << "Insufficient funds." << endl;
    } else {
        double newBalance = currentBalance - amount;
        account->setBalance(newBalance);
        StatisticsTracker::incrementWithdrawals();
        cout << "Withdrawal successful. Remaining balance: " << newBalance << endl;
    }
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
