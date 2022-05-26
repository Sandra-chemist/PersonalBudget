#ifndef FINANCEMANAGER_H
#define FINANCEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>


//#include "IncomeManager.h"
#include "ExpenseManager.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"

using namespace std;

class FinanceManager {
    const int LOGGED_IN_USER_ID;
  //  IncomeManager incomeManager;
  //  ExpenseManager expenseManager;
    FileWithIncomes fileWithIncomes;
     FileWithExpenses fileWithExpenses;
   Date date;
    float totalIncome;
        float totalExpense;
    vector <Income> incomes;
   vector <Expense> expenses;

public:
    FinanceManager(int loggedInUserId, string fileNameWithIncomes, string fileNameWithExpenses)
        : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(fileNameWithIncomes), fileWithExpenses(fileNameWithExpenses) {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };

    void displayBalanceForCurrentMonth();

    Income provideDataOfNewIncome();
    void addIncome();
    int getNewIncomeId();
    void showAllIncomesForCurrentMonth();
    void countTotalIncome(vector <Income>::iterator itr);

    void addExpense();
    Expense provideDataOfNewExpense();
    int getNewExpenseId();
    void showAllExpensesForCurrentMonth();
    void countTotalExpense(vector <Expense>::iterator itr);

};
#endif
