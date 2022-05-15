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

    FileWithIncomes fileWithIncomes;
    vector <Income> incomes;
public:
    IncomeManager(string fileNameWithIncomes) : fileWithIncomes(fileNameWithIncomes){}
        Income provideDataOfNewIncome();
    void addIncome();
    int getNewIncomeId();
};
#endif
