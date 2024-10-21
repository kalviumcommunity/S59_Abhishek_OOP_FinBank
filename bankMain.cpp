#include "bankingFunc.cpp"
#include <iostream>
using namespace std;

int main() {
    SavingsAccount *savings = new SavingsAccount(1002, 2000.0, 0.05);
    ATM atm;

    cout << "--- Savings Account ---"<<endl;
    atm.displayBalance(savings);

    atm.deposit(savings, 500.0);
    atm.withdraw(savings, 200.0);

    double interest = savings->calculateInterest();
    cout << "Calculated Interest: " << interest << endl;

    atm.displayBalance(savings);

    BankBranch *branch = new BankBranch(1003, 10000.0, "Main Branch");

    cout << "--- Bank Branch ---"<<endl;
    branch->displayBranchDetails();

    atm.deposit(branch, 1500.0);
    atm.withdraw(branch, 1200.0);

    cout << "Updated Branch Details:"<<endl;
    branch->displayBranchDetails();

    int option;
    cout << "Press '1' for checking Total Deposits and '2' for Total Withdrawals: ";
    cin >> option; 
    atm.displayStats(option); 

    delete savings;
    delete branch;

    return 0;
}
