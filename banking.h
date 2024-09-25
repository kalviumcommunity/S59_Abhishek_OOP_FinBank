#ifndef BANKING_H
#define BANKING_H

class Account {
private:
    int accountNumber;
    double balance;

public:
    Account();  
    Account(int accNum, double initialBalance);
    ~Account();
    double getBalance() const;
    void setBalance(double newBalance);
    int getAccountNumber() const;
};

class ATM {
private:
    double transactionLimit;
    static int totalDeposits;
    static int totalWithdrawals;
public:
    ATM();  
    ATM(double limit);  
    ~ATM();
    double getTransactionLimit() const;
    void setTransactionLimit(double newLimit);
    void deposit(Account* account, double amount);
    void withdraw(Account* account, double amount);
    void displayBalance(const Account* account) const;
    static void displayStats(int option);
};
#endif
