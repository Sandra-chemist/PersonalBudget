#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"
#include "AdditionalMethodsOnDate.h"

using namespace std;

class FileWithExpenses : public XmlFile {

    string fileNameWithExpenses;
    vector <Expense> expenses;
    int loggedInUserId;
    int lastExpenseId;

public:
    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses) {};
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedInUserId);
    int getNewExpenseId();
    void displayExpense(Expense expense);
};
#endif
