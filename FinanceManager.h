#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>


#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

using namespace std;

class FinanceManager {
    const int ID_LOGGED_USER;
    IncomeManager incomeManager;
    ExpenseManager expenseManager;
    vector <Income> incomes;
    vector <Expense> expenses;

public:
    FinanceManager(int loggedInUserId, string fileNameWithIncomes, string fileNameWithExpenses)
        : ID_LOGGED_USER(loggedInUserId), fileWithIncomes(fileNameWithIncomes), fileNameWithExpenses(fileNameWithExpenses) {
        incomes = fileWithIncomes.loadIncomesFromFile(ID_LOGGED_USER);
        expenses = fileWithExpenses.loadExpensesFromFile(ID_LOGGED_USER);
    };


    void showAllIncomesForCurrentMonth();
    void showAllExpensesForCurrentMonth();
    void displayBalanceForCurrentMonth();

};
#endif
