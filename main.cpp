#include <iostream>
#include "FinanceManager.h"
using namespace std;

int main() {
    FinanceManager manager;
    int choice;

    do {
        cout << "\n--- Finance Manager ---\n";
        cout << "1. Add Transaction\n";
        cout << "2. View Transactions\n";
        cout << "3. View Totals\n";
        cout << "4. View Balance\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

                                                                                    
        if (choice == 1) {
            string category;
            double amount;
            char type;
            cout << "Enter category: ";
            cin >> category;
            cout << "Enter amount: ";
            cin >> amount;
            cout << "Is this income? (y/n): ";
            cin >> type;
            manager.addTransaction(category, amount, (type == 'y'));
        } else if (choice == 2) {
            manager.viewTransactions();
        } else if (choice == 3) {
            cout << "Total Income: $" << manager.getTotalIncome() << endl;
            cout << "Total Expenses: $" << manager.getTotalExpenses() << endl;
        } else if (choice == 4) {
            cout << "Balance: $" << manager.getBalance() << endl;
        }
    } while (choice != 5);

    cout << "Goodbye!\n";
    return 0;
}