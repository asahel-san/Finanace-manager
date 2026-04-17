#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Transaction {
    string category;
    double amount;
    bool isIncome; // true for income, false for expense
    Transaction* next;
};

class FinanceManager {
private:
    Transaction* head;

 public:
     FinanceManager();
     void addTransaction(const string& category, double amount, bool isIncome);
    void viewTransactions();
    void calculateTotals(double& totalIncome, double& totalExpenses);
    double getCurrentBalance();
    void sortTransactions();
    ~FinanceManager();
};
            
#endif