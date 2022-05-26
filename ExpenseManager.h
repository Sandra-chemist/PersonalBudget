#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Expense.h"
#include "Date.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class ExpenseManager {

    const int LOGGED_IN_USER_ID;
    FileWithExpenses fileWithExpenses;
    vector <Expense> expenses;
    Date date;
    float totalExpense;

public:
    ExpenseManager(string fileNameWithExpenses, int loggedInUserId)
        : fileWithExpenses(fileNameWithExpenses), LOGGED_IN_USER_ID(loggedInUserId) {
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_IN_USER_ID);
    };
    void addExpense();
    Expense provideDataOfNewExpense();
    int getNewExpenseId();
    void showAllExpensesForCurrentMonth();
    void countTotalExpense(vector <Expense>::iterator itr);


};
#endif
