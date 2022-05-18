#ifndef FILEWITEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithExpenses : public XmlFile {

    string fileNameWithExpenses;
    vector <Expense> expenses;
    int loggedInUserId;

public:
    FileWithExpenses(string fileNameWithExpenses) : XmlFile(fileNameWithExpenses) {};

    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedInUserId);
    void displayExpense(vector <Expense>::iterator itr);
};
#endif
