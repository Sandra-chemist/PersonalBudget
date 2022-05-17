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

    public:
    Expense provideDataOfNewExpense();

};
#endif
