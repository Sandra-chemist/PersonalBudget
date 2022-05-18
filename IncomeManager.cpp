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
    int otherDate;

    income.setIncomeId(getNewIncomeId());
    income.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add income with current date?" << endl << endl;
    cout << "If yes, enter '1',if you want to choose different date - enter '2'." << endl;
    choice = AuxiliaryMethods::loadChar();

    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    if (choice == '1') {
        currentDate = date.getCurrentDate();
        income.setDate(currentDate);
    } else if (choice == '2') {
        do {
            otherDate = date.writeOtherDateThanCurrent();
        } while (date.isDateRight(otherDate) == false);
      //  int otherDateAsInt = AuxiliaryMethods::convertStringToInt(otherDate);
        income.setDate(otherDate);
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
void IncomeManager::showAllIncomesForCurrentMonth() {
    Income income;
    int minDate = (date.getCurrentDate()/100)*100 + 1;
    cout << "MinDate: " << minDate << endl;
    int maxDate = (date.getCurrentDate()/100 + 1) * 100;
    cout << "MaxDate: " << maxDate << endl;
    system ("pause");

    system("cls");
    if (!incomes.empty()) {
        cout << ">>> DISPLAY BALANCE FOR CURRENT MONTH <<<" << endl << endl;
        for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr++) {
             int currentDate = itr -> getDate();

          if (currentDate >= minDate && currentDate <= maxDate) {
                fileWithIncomes.displayIncome(itr);
           }
        }
        system("pause");
    }
}
