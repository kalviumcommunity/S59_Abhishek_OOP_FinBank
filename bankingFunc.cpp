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

DepositTransaction::DepositTransaction(double amount) : amount(amount) {}

void DepositTransaction::process(Account* account) {
    account->setBalance(account->getBalance() + amount);
    cout << "Deposited " << amount << ". New Balance: " << account->getBalance() << endl;
}

WithdrawalTransaction::WithdrawalTransaction(double amount) : amount(amount) {}

void WithdrawalTransaction::process(Account* account) {
    double currentBalance = account->getBalance();
    if (amount > currentBalance) {
        cout << "Insufficient funds." << endl;
    } else {
        account->setBalance(currentBalance - amount);
        cout << "Withdrew " << amount << ". Remaining Balance: " << account->getBalance() << endl;
    }
}

void TransactionProcessor::addTransaction(Transaction* transaction) {
    transactions.push_back(transaction);
}

void TransactionProcessor::processTransactions(Account* account) {
    for (Transaction* transaction : transactions) {
        transaction->process(account);
    }
}

TransactionProcessor::~TransactionProcessor() {
    for (Transaction* transaction : transactions) {
        delete transaction;
    }
}

DepositStats::DepositStats() : totalDeposits(0) {}

void DepositStats::track() {
    totalDeposits++;
}

void DepositStats::displayStats() const {
    cout << "Total Deposits: " << totalDeposits << endl;
}

WithdrawalStats::WithdrawalStats() : totalWithdrawals(0) {}

void WithdrawalStats::track() {
    totalWithdrawals++;
}

void WithdrawalStats::displayStats() const {
    cout << "Total Withdrawals: " << totalWithdrawals << endl;
}
