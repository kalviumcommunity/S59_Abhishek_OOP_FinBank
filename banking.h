#ifndef BANKING_H
#define BANKING_H

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
public:
    void deposit(Account &account, double amount);
    void withdraw(Account &account, double amount);
    void displayBalance(const Account &account) const;
};
#endif