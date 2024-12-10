#ifndef BANKING_H
#define BANKING_H

#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accNum, double initialBalance);
    virtual ~Account() {}
    virtual void deposit(double amount);
    virtual void withdraw(double amount);
    virtual void displayAccountInfo() const;
    double getBalance() const;
    int getAccountNumber() const;
};

class InterestBearingAccount : public Account {
public:
    InterestBearingAccount(int accNum, double initialBalance);
    virtual double calculateInterest() const = 0;
    virtual void applyInterest() = 0;
};

class SavingsAccount : public InterestBearingAccount {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double initialBalance, double rate);
    double calculateInterest() const override;
    void applyInterest() override;
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
