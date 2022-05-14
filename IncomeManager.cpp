#include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = provideDataOfNewIncome();

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

   /* if (fileWithIncomes.addIncomeToFile(income))
        cout << "New income has been added" << endl;
    else
        cout << "Mistake. Could not add new income to the file." << endl;
        system("pause");*/
}
Income IncomeManager::provideDataOfNewIncome() {
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
