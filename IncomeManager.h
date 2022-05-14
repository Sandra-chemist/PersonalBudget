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

    vector <Income> incomes;
public:

    Income provideDataOfNewIncome();
    void addIncome();
};
#endif
