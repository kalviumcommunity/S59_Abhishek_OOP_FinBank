#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
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

class TransactionProcessor {
public:
    void deposit(Account* account, double amount);
    void withdraw(Account* account, double amount);
    void displayBalance(const Account* account) const;
};

class StatisticsTracker {
private:
    static int totalDeposits;
    static int totalWithdrawals;

public:
    static void incrementDeposits();
    static void incrementWithdrawals();
    static void displayStats(int option);
};

#endif
