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
};

class ATM {
private:
    static int totalDeposits;
    static int totalWithdrawals;

public:
    static int getTotalDeposits();
    static void setTotalDeposits(int deposits);

    static int getTotalWithdrawals();
    static void setTotalWithdrawals(int withdrawals);

    void deposit(Account* account, double amount);
    void withdraw(Account* account, double amount);
    void displayBalance(const Account* account) const;
    static void displayStats(int option);
};

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double initialBalance, double rate);
    SavingsAccount();

    double calculateInterest();
    void applyInterest();
};

class BankBranch : public Account, public ATM {
private:
    string branchName;

public:
    BankBranch(int accNum, double initialBalance, const string& name);
    void displayBranchDetails() const;
};

#endif
