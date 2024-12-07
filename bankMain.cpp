#include "banking.h"
#include "bankingFunc.cpp"
#include <iostream>
using namespace std;

int main() {
    SavingsAccount* savings = new SavingsAccount(1003, 10000.0, 0.05);

    TransactionProcessor atmProcessor;

    cout << "\n--- Savings Account ---\n";
    savings->displayAccountInfo();

    DepositTransaction deposit(500.0);
    WithdrawalTransaction withdraw(200.0);

    atmProcessor.addTransaction(&deposit);
    atmProcessor.addTransaction(&withdraw);

    atmProcessor.processTransactions(savings);

    double interest = savings->calculateInterest();
    cout << "Calculated Interest: " << interest << endl;
    savings->applyInterest();
    savings->displayAccountInfo();

    DepositStats depositStats;
    WithdrawalStats withdrawalStats;

    depositStats.track();
    withdrawalStats.track();

    cout << "\n--- Statistics ---\n";
    cout << "Total Deposits and Withdrawals Stats:\n";
    depositStats.displayStats();
    withdrawalStats.displayStats();

    delete savings;

    return 0;
}
