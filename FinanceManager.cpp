#include "FinanceManager.h"
#include <utility> // for std::swap

FinanceManager::FinanceManager() : head(nullptr) {
     addTransaction("Salary", 3000, true);
     addTransaction("Groceries", 200, false);
     addTransaction("Freelance", 1500, true);
     addTransaction("Entertainment", 100, false);
  }

void FinanceManager::addTransaction(const string& category, double amount, bool isIncome) {
    Transaction* newTransaction = new Transaction{category, amount, isIncome, head};
    head = newTransaction;
}

void FinanceManager::viewTransactions() {
    Transaction* current = head;
    cout << fixed << setprecision(2);
    while (current) {
         cout << (current->isIncome ? "Income: " : "Expense: ") 
             << current->category << " - $" << current->amount << endl;
        current = current->next;

     }
 }

 void FinanceManager::calculateTotals(double& totalIncome, double& totalExpenses) {
    Transaction* current = head;
    while (current) {
        if (current->isIncome) {
         totalIncome += current->amount;
        } else {
        totalExpenses += current->amount;
        }
        current = current->next;
    }
 }

 double FinanceManager::getCurrentBalance() {
     double totalIncome = 0, totalExpenses = 0;
     calculateTotals(totalIncome, totalExpenses);
    return totalIncome - totalExpenses;
}

void FinanceManager::sortTransactions() {
    if (!head || !head->next) return;

    bool swapped;
    while {
        swapped = false;
        Transaction* current = head;
        while (current->next) {
            if (current->amount > current->next->amount){
                swap(current->amount, current->next->amount);
                swap(current->category, current->next->category);
                swap(current->isIncome, current->next->isIncome);
                swapped = true;
            }
            current = current->next;
        }
     } while (swapped);
}

FinanceManager::~FinanceManager() {
    while (head) {
    Transaction* temp = head;
    head = head->next;
     delete temp;
     }
}