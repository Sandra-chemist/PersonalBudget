#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "Income.h"
#include "FileWithIncomes.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeManager {

    const int LOGGED_IN_USER_ID;
    FileWithIncomes fileWithIncomes;
    vector <Income> incomes;
public:
    IncomeManager(string fileNameWithIncomes, int loggedInUserId)
    : fileWithIncomes(fileNameWithIncomes), LOGGED_IN_USER_ID(loggedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_IN_USER_ID);
    };

    Income provideDataOfNewIncome();
    void addIncome();
    int getNewIncomeId();
};
#endif