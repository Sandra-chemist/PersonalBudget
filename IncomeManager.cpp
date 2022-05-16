#include "IncomeManager.h"

void IncomeManager::addIncome() {
    Income income;
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = provideDataOfNewIncome();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
    cout << "New income has been added" << endl;
}
Income IncomeManager::provideDataOfNewIncome() {
    Income income;
    string item;
    float amount;
    int currentDate;
    char choice;
    string dateAsString;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add income with current date?" << endl;
    cout << endl;
    cout << "If yes, enter '1',if you want to choose different date - enter '2'." << endl;
    choice = AuxiliaryMethods::loadChar();

    if (choice == '1')
    {
        currentDate = date.getCurrentDate();
        dateAsString = AuxiliaryMethods::convertIntToString(currentDate);
        income.setDate(dateAsString);
    }
    else if (choice == '2')
    {
        cout << "Bêdzie wporwadzona inna data" << endl;
    }

    cout << "Enter item of income: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Enter amount of income: ";
    amount = AuxiliaryMethods::loadFloat();
    income.setAmount(amount);

    return income;
}
int IncomeManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
