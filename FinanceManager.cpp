#include "FinanceManager.h"

void FinanceManager::addIncome() {
    Income income;
    system("cls");
    cout << " >>> ADDING NEW INCOME <<<" << endl << endl;
    income = provideDataOfNewIncome();
    incomes.push_back(income);

    fileWithIncomes.addIncomeToFile(income);
    cout << "New income has been added" << endl;
}
Income FinanceManager::provideDataOfNewIncome() {
    Income income;
    string item;
    string amountAsString;
    float amount, amountAsFloat;
    int currentDate, otherDate;
    char choice;

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
        income.setDate(otherDate);
    }
    cout << "Enter item of income: ";
    item = AuxiliaryMethods::loadLine();
    income.setItem(item);

    cout << "Enter amount of income: ";
    amountAsString = AuxiliaryMethods::loadLine();
    string amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
    amountAsFloat = AuxiliaryMethods::convertStringToFloat(amountWithDot);
    amount = AuxiliaryMethods::writeDownTwoDecimalPlaces(amountAsFloat);
    income.setAmount(amount);
    return income;
}
int FinanceManager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}
void FinanceManager::countTotalIncome(vector <Income>::iterator itr) {
    totalIncome += itr -> getAmount();
}
void FinanceManager::addExpense() {
    Expense expense;
    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = provideDataOfNewExpense();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
    cout << "New expense has been added" << endl;
}
Expense FinanceManager::provideDataOfNewExpense() {
    Expense expense;
    string item;
    string amountAsString;
    float amount;
    int currentDate, otherDate;
    char choice;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add expense with current date?" << endl << endl;
    cout << "If yes, enter '1',if you want to choose different date - enter '2'." << endl;
    choice = AuxiliaryMethods::loadChar();

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    if (choice == '1') {
        currentDate = date.getCurrentDate();
        expense.setDate(currentDate);
    } else if (choice == '2') {
        do {
            otherDate = date.writeOtherDateThanCurrent();
        } while (date.isDateRight(otherDate) == false);
        expense.setDate(otherDate);
    }
    cout << "Enter item of expense: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Enter amount of expense: ";
    amountAsString = AuxiliaryMethods::loadLine();
    string amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
    amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
    expense.setAmount(amount);
    return expense;
}
int FinanceManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}
void FinanceManager::displayBalanceForCurrentMonth() {
    totalIncome = 0;
    totalExpense = 0;
    int startDate = (date.getCurrentDate()/100)*100 + 1;
    int endDate = (date.getCurrentDate()/100 + 1) * 100;

    system("cls");
    if (!incomes.empty()) {
        cout << ">>> DISPLAY BALANCE FOR CURRENT MONTH <<<" << endl << endl;
        for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr ++) {
            if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                int currentDate = itr -> getDate();
                if (currentDate >= startDate && currentDate <= endDate) {
                    fileWithIncomes.displayIncome(*itr);
                    // sortIncomes();
                    countTotalIncome(itr);
                }
            }
        }
    }
    if (!expenses.empty()) {
        for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr ++) {
            if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                int currentDate = itr -> getDate();
                if (currentDate >= startDate && currentDate <= endDate) {
                    fileWithExpenses.displayExpense(*itr);
                    //  sortExpenses();
                    countTotalExpense(itr);
                }
            }
        }
    }
    balanceOfIncomesAndExpenses();
}
void FinanceManager::countTotalExpense(vector <Expense>::iterator itr) {
    totalExpense += itr -> getAmount();
}
struct sortIncomesByDate {
    inline bool operator() (Income& firstDate, Income& secondDate) {
        return (firstDate.getDate() > secondDate.getDate());
    }
};
void FinanceManager::sortIncomes() {
    sort(incomes.begin(), incomes.end(), sortIncomesByDate());
}
struct sortExpensesByDate {
    inline bool operator() (Expense& firstDate, Expense& secondDate) {
        return (firstDate.getDate() > secondDate.getDate());
    }
};
void FinanceManager::sortExpenses() {
    sort(expenses.begin(), expenses.end(), sortExpensesByDate());
}
void FinanceManager::displayBalanceForPreviousMonth() {
    totalIncome = 0;
    totalExpense = 0;
    int startDate = (date.getCurrentDate()/100-1)*100 + 1;
    int endDate = (date.getCurrentDate()/100) * 100;

    system("cls");
    if (!incomes.empty()) {
        cout << ">>> DISPLAY BALANCE FOR PREVIOUS MONTH <<<" << endl << endl;
        for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr++) {
            if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                int currentDate = itr -> getDate();
                if (currentDate >= startDate && currentDate <= endDate) {
                    fileWithIncomes.displayIncome(*itr);
                    sortIncomes();
                    countTotalIncome(itr);
                }
            }
        }
    }
    if (!expenses.empty()) {
        for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++) {
            if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                int currentDate = itr -> getDate();
                if (currentDate >= startDate && currentDate <= endDate) {
                    fileWithExpenses.displayExpense(*itr);
                    sortExpenses();
                    countTotalExpense(itr);
                }
            }
        }
    }
    balanceOfIncomesAndExpenses();
}
void FinanceManager::balanceOfIncomesAndExpenses() {
    cout << "Total income: " << totalIncome << endl;
    cout << "Total expense: " << totalExpense << endl;
    cout << "Month Balance: " << totalIncome - totalExpense << endl << endl;
    system("pause");
}
void FinanceManager::displayBalanceForSelectedMonth() {
    totalIncome = 0;
    totalExpense = 0;
    string startDate;
    string endDate;

    cout << endl;
    cout << "Enter the starting date in format YYYY-MM-DD: " << endl;
    cin >> startDate;
    cout << endl;

    cout << "Enter the ending date in format YYYY-MM-DD: " << endl;
    cin >> endDate;
    cout << endl;

    string startDateWithoutDash = AdditionalMethodsOnDate::removeDashFromDate(startDate);
    string endDateWithoutDash = AdditionalMethodsOnDate::removeDashFromDate(endDate);

    int startDateAsInt = AuxiliaryMethods::convertStringToInt(startDateWithoutDash);
    int endDateAsInt = AuxiliaryMethods::convertStringToInt(endDateWithoutDash);

    system("cls");
    if (startDateAsInt < endDateAsInt) {
        if (!incomes.empty()) {
            cout << ">>> DISPLAY BALANCE FOR SELECTED MONTH <<<" << endl << endl;

            for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr++) {
                if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                    int date = itr -> getDate();
                    if (date >= startDateAsInt && date <= endDateAsInt) {
                        fileWithIncomes.displayIncome(*itr);
                        sortIncomes();
                        countTotalIncome(itr);
                    }
                }
            }
        }
        if (!expenses.empty()) {
            for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++) {
                if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                    int date = itr -> getDate();
                    if (date >= startDateAsInt && date <= endDateAsInt) {
                        fileWithExpenses.displayExpense(*itr);
                        sortExpenses();
                        countTotalExpense(itr);
                    }
                }
            }
        }
        balanceOfIncomesAndExpenses();
    } else if (startDateAsInt > endDateAsInt) {
        cout << "Start date is later than end date" << endl << endl;
        system("pause");
    }
}



