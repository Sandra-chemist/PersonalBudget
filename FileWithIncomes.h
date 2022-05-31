#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "XmlFile.h"
#include "AuxiliaryMethods.h"
#include "AdditionalMethodsOnDate.h"

using namespace std;

class FileWithIncomes : public XmlFile {

    string fileNameWithIncomes;
    vector <Income> incomes;
    int loggedInUserId;
    int lastIncomeId;

public:
    FileWithIncomes(string fileNameWithIncomes) : XmlFile(fileNameWithIncomes) {};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedInUserId);
    int getLastIncomeId();
    int getNewIncomeId();
    void displayIncome(Income income);
};
#endif
