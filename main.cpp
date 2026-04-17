#include "FinanceManager.h"

int main() {
    FinanceManager manager;
    manager.viewTransactions();

    cout << "\nCurrent Balance: $" << manager.getCurrentBalance() << endl;

    cout << "\nSorting transactions by amount...\n";
    manager.sortTransactions();
    manager.viewTransactions();

    return 0;
 }