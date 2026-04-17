#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <string>
using namespace std;

class Transaction {
public:
    string category;
    double amount;
    bool isIncome;
    Transaction* next;

    Transaction(const string& category, double amount, bool isIncome, Transaction* next = nullptr)
        : category(category), amount(amount), isIncome(isIncome), next(next) {}
};

class FinanceManager {
public:
    FinanceManager();
    void addTransaction(const string& category, double amount, bool isIncome);
    void viewTransactions();
    double getTotalIncome();
    double getTotalExpenses();
    double getBalance();
    void sortTransactions();
private:
    Transaction* head;
};

 #endif