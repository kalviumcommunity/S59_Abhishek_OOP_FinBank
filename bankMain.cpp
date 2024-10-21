#include "bankingFunc.cpp"
#include <iostream>
using namespace std;

int main() {
    SavingsAccount *savings1 = new SavingsAccount();
    SavingsAccount *savings2 = new SavingsAccount(1002, 2000.0, 0.05);
    ATM atm;

    cout << "\n--- Savings Account (Default) ---\n";
    atm.displayBalance(savings1);

    double interest1 = savings1->calculateInterest();
    cout << "Calculated Interest: " << interest1 << endl;

    savings1->applyInterest();
    atm.displayBalance(savings1);

    cout << "\n--- Savings Account 2 ---\n";
    atm.displayBalance(savings2);

    atm.deposit(savings2, 500.0);
    atm.withdraw(savings2, 200.0);

    double interest2 = savings2->calculateInterest();
    cout << "Calculated Interest: " << interest2 << endl;

    savings2->applyInterest();
    atm.displayBalance(savings2);

    BankBranch *branch = new BankBranch(1003, 10000.0, "Main Branch");

    cout << "\n--- Bank Branch ---\n";
    branch->displayBranchDetails();

    atm.deposit(branch, 1500.0);
    atm.withdraw(branch, 1200.0);

    cout << "\nUpdated Branch Details:\n";
    branch->displayBranchDetails();

    int option;
    cout << "Press '1' for checking Total Deposits and '2' for Total Withdrawals: ";
    cin >> option;
    atm.displayStats(option);

    delete savings1;
    delete savings2;
    delete branch;

    return 0;
}
