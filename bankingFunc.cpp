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

int ATM::totalDeposits = 0;
int ATM::totalWithdrawals = 0;

int ATM::getTotalDeposits() {
    return totalDeposits;
}

void ATM::setTotalDeposits(int deposits) {
    totalDeposits = deposits;
}

int ATM::getTotalWithdrawals() {
    return totalWithdrawals;
}

void ATM::setTotalWithdrawals(int withdrawals) {
    totalWithdrawals = withdrawals;
}

void ATM::deposit(Account* account, double amount) {
    double newBalance = account->getBalance() + amount;
    account->setBalance(newBalance);
    setTotalDeposits(getTotalDeposits() + 1);
    cout << "Deposit successful. New balance: " << newBalance << endl;
}

void ATM::withdraw(Account* account, double amount) {
    double currentBalance = account->getBalance();
    if (amount > currentBalance) {
        cout << "Insufficient funds." << endl;
    } else {
        double newBalance = currentBalance - amount;
        account->setBalance(newBalance);
        setTotalWithdrawals(getTotalWithdrawals() + 1);
        cout << "Withdrawal successful. Remaining balance: " << newBalance << endl;
    }
}

void ATM::displayBalance(const Account* account) const {
    account->displayAccountInfo();
}

void ATM::displayStats(int option) {
    if (option == 1) {
        cout << "Total Deposits: " << getTotalDeposits() << endl;
    } else if (option == 2) {
        cout << "Total Withdrawals: " << getTotalWithdrawals() << endl;
    }
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

BankBranch::BankBranch(int accNum, double initialBalance, const string& name) 
    : Account(accNum, initialBalance), branchName(name) {}

double BankBranch::calculateInterest() const {
    return 0.0;
}

void BankBranch::displayAccountInfo() const {
    cout << "Branch: " << branchName << endl;
    Account::displayAccountInfo();
}
