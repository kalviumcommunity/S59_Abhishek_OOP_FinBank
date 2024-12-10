#include "banking.h"
#include "bankingFunc.cpp"
#include <iostream>
using namespace std;

int main() {
    SavingsAccount* savings = new SavingsAccount(1003, 10000.0, 0.05);

    TransactionProcessor atmProcessor;

    cout << "\n--- Savings Account ---\n";
    savings->displayAccountInfo();

    atmProcessor.deposit(savings, 500.0);
    atmProcessor.withdraw(savings, 200.0);

    cout << "\n--- After Transactions ---\n";
    savings->displayAccountInfo();

    double interest = savings->calculateInterest();
    cout << "\nCalculated Interest: " << interest << endl;

    savings->applyInterest();

    cout << "\n--- After Applying Interest ---\n";
    savings->displayAccountInfo();

    cout << "\n--- Statistics ---\n";
    StatisticsTracker::displayStats(1); 
    StatisticsTracker::displayStats(2);

    delete savings;

    return 0;
}
