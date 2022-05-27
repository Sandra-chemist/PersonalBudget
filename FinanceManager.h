#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "ExpenseManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "Date.h"

using namespace std;

class FinanceManager {
    const int LOGGED_IN_USER_ID;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;
    Date date;
    float totalIncome;
    float totalExpense;
    vector <Income> incomes;
    vector <Expense> expenses;

    void showAllIncomesForCurrentMonth();
    void showAllExpensesForCurrentMonth();
    void showAllIncomesForPreviousMonth();
    void showAllExpensesForPreviousMonth();

    void sortIncomes();
    void sortExpenses();

public:
    FinanceManager(string fileNameWithIncomes, string fileNameWithExpenses, int loggedInUserId)
        : fileWithIncomes(fileNameWithIncomes), fileWithExpenses(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId) {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };
    void addIncome();
    void addExpense();

    Income provideDataOfNewIncome();
    Expense provideDataOfNewExpense();

    int getNewIncomeId();
    int getNewExpenseId();

    void countTotalIncome(vector <Income>::iterator itr);
    void countTotalExpense(vector <Expense>::iterator itr);

    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForSelectedMonth();
};
#endif
