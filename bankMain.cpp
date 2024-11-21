#include "banking.h"
#include "bankingFunc.cpp"
#include <iostream>
using namespace std;

int main() {
    SavingsAccount *savings = new SavingsAccount(1003, 10000.0, 0.05);

    TransactionProcessor atmProcessor;

    cout << "\n--- Savings Account ---\n";
    atmProcessor.displayBalance(savings);

    atmProcessor.deposit(savings, 500.0);
    atmProcessor.withdraw(savings, 200.0);

    double interest = savings->calculateInterest();
    cout << "Calculated Interest: " << interest << endl;
    savings->applyInterest();
    atmProcessor.displayBalance(savings);

    int option;
    cout << "\nPress '1' for checking Total Deposits and '2' for Total Withdrawals: ";
    cin >> option;
    StatisticsTracker::displayStats(option);

    delete savings;

    return 0;
}
