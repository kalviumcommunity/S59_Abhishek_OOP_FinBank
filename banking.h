#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance);
    double getBalance() const;
    void setBalance(double newBalance);
    int getAccountNumber() const;
    virtual double calculateInterest() const = 0;
    virtual void displayAccountInfo() const;
    virtual ~Account() {}
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double initialBalance, double rate);
    SavingsAccount();
    double calculateInterest() const override;
    void applyInterest();
    void displayAccountInfo() const override;
};

class Transaction {
public:
    virtual void process(Account* account) = 0;
    virtual ~Transaction() {}
};

class DepositTransaction : public Transaction {
private:
    double amount;

public:
    DepositTransaction(double amount);
    void process(Account* account) override;
};

class WithdrawalTransaction : public Transaction {
private:
    double amount;

public:
    WithdrawalTransaction(double amount);
    void process(Account* account) override;
};

class TransactionProcessor {
private:
    vector<Transaction*> transactions;

public:
    void addTransaction(Transaction* transaction);
    void processTransactions(Account* account);
    ~TransactionProcessor();
};

class StatisticsTracker {
public:
    virtual void track() = 0;
    virtual void displayStats() const = 0;
    virtual ~StatisticsTracker() {}
};

class DepositStats : public StatisticsTracker {
private:
    int totalDeposits;

public:
    DepositStats();
    void track() override;
    void displayStats() const override;
};

class WithdrawalStats : public StatisticsTracker {
private:
    int totalWithdrawals;

public:
    WithdrawalStats();
    void track() override;
    void displayStats() const override;
};

#endif
