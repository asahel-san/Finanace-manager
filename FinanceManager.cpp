#include "FinanceManager.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

FinanceManager::FinanceManager() : head(nullptr) {}

void FinanceManager::addTransaction(const string& category, double amount, bool isIncome) {
    Transaction* newTransaction = new Transaction(category, amount, isIncome, head);
    head = newTransaction;
}

void FinanceManager::viewTransactions() {
    Transaction* current = head;
    cout << fixed << setprecision(2);
    while (current) {
        cout << (current->isIncome ? "Income: " : "Expense: ");
        cout << current->category << " - $" << current->amount << endl;
        current = current->next;
    }
}

double FinanceManager::getTotalIncome() {
    double total = 0;
    Transaction* current = head;
    while (current) {
        if (current->isIncome) total += current->amount;
        current = current->next;
    }
    return total;
}

double FinanceManager::getTotalExpenses() {
    double total = 0;
    Transaction* current = head;
    while (current) {
        if (!current->isIncome) total += current->amount;
        current = current->next;
    }
    return total;
}

double FinanceManager::getBalance() {
    return getTotalIncome() - getTotalExpenses();
}

void FinanceManager::sortTransactions() {
                                                                                                                                
    vector<Transaction*> list;
    Transaction* current = head;
    while (current) {
         list.push_back(current);
        current = current->next;
    }

    sort(list.begin(), list.end(), [](Transaction* a, Transaction* b) {
        return a->amount < b->amount;
    });

    for (auto* t : list) {
        cout << (t->isIncome ? "Income: " : "Expense: ");
        cout << t->category << " - $" << t->amount << endl;
        }
    }