#include "IncomeManager.h"

Income IncomeManager::addIncome()
{
        Income income;
        string item;
        float amount;

        cout << "Enter item of income: ";
        item = AuxiliaryMethods::loadLine();
        income.setItem(item);

        cout << "Enter amount of income in xxx.xx format: ";
        amount = AuxiliaryMethods::loadFloat();
        income.setAmount(amount);

        return income;
}
