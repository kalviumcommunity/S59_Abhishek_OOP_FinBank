#include "banking.h"
#include <iostream>
using namespace std;

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

void ATM::deposit(Account *account, double amount) {
    double newBalance = account->getBalance() + amount;
    account->setBalance(newBalance);
    totalDeposits++;
    cout << "Deposit successful. New balance: " << newBalance << endl;
}

void ATM::withdraw(Account *account, double amount) {
    double currentBalance = account->getBalance();
    if (amount > currentBalance) {
        cout << "Insufficient funds." << endl;
    } else {
        double newBalance = currentBalance - amount;
        account->setBalance(newBalance);
        totalWithdrawals++;
        cout << "Withdrawal successful. Remaining balance: " << newBalance << endl;
    }
}

void ATM::displayBalance(const Account *account) const {
    cout << "Account Number: " << account->getAccountNumber() << endl;
    cout << "Current Balance: " << account->getBalance() << endl;
}
void ATM::displayStats(int option) {
    cout<<"Press '1' for checking Total Deposits and '2' for Total Withdrawals: "<<endl;
    cin>>option;
    if (option == 1) {
        cout << "Total Deposits: " << totalDeposits << endl;
    } else if (option == 2) {
        cout << "Total Withdrawals: " << totalWithdrawals << endl;
    }
}