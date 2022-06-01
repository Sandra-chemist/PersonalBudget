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
    string amountWithDot;
    float amount;
    int currentDate, otherDate;
    char choice;

    income.setIncomeId(fileWithIncomes.getNewIncomeId() + 1);
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
    amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
    if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) == true) {
        amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
        income.setAmount(amount);
    } else {
        cout << "Enter amount of income: ";
        amountAsString = AuxiliaryMethods::loadLine();
        amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
        {
            if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) != true) {
                cout << "Enter amount of income: ";
                amountAsString = AuxiliaryMethods::loadLine();
                amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
                amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
                income.setAmount(amount);
                if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) == true) {
                    amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
                    income.setAmount(amount);
                }
            }
            if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) == true) {
                amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
                income.setAmount(amount);
            }
        }
    }
    return income;
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

    expense.setExpenseId(fileWithExpenses.getNewExpenseId() + 1);
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
    if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) == true) {
        amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
        expense.setAmount(amount);
    } else {
        cout << "Enter amount of expense: ";
        amountAsString = AuxiliaryMethods::loadLine();
        amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
        {
            if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) != true) {
                cout << "Enter amount of expense: ";
                amountAsString = AuxiliaryMethods::loadLine();
                amountWithDot = AuxiliaryMethods::convertCommaToDot(amountAsString);
                amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
                expense.setAmount(amount);
                if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) == true) {
                    amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
                    expense.setAmount(amount);
                }
            }
            if (AuxiliaryMethods::calculatePlaceAfterComma(amountWithDot) == true) {
                amount = AuxiliaryMethods::convertStringToFloat(amountWithDot);
                expense.setAmount(amount);
            }
        }
    }
    return expense;
}
struct sortIncomesByDate {
    bool operator() (Income firstIncome, Income secondIncome) {
        return (firstIncome.getDate() > secondIncome.getDate());
    }
};
struct sortExpensesByDate {
    bool operator() (Expense firstExpense, Expense secondExpense) {
        return (firstExpense.getDate() > secondExpense.getDate());
    }
};
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
                    sort(incomes.begin(), incomes.end(), sortIncomesByDate());
                    fileWithIncomes.displayIncome(*itr);
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
                    sort(expenses.begin(), expenses.end(), sortExpensesByDate());
                    fileWithExpenses.displayExpense(*itr);
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
                    sort(incomes.begin(), incomes.end(), sortIncomesByDate());
                    fileWithIncomes.displayIncome(*itr);
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
                    sort(expenses.begin(), expenses.end(), sortExpensesByDate());
                    fileWithExpenses.displayExpense(*itr);
                    countTotalExpense(itr);
                }
            }
        }
    }
    balanceOfIncomesAndExpenses();
}
void FinanceManager::balanceOfIncomesAndExpenses() {
    cout << "Total income:  " << totalIncome << endl;
    cout << "Total expense: " << totalExpense << endl;
    cout << "Month Balance: " << totalIncome - totalExpense << endl << endl;
    system("pause");
}
void FinanceManager::displayBalanceForSelectedPeriod() {
    totalIncome = 0;
    totalExpense = 0;
    int startDate, endDate;

    system("cls");
    cout << "Enter the starting date" << endl;
    startDate = date.writeOtherDateThanCurrent();
    while (date.isDateRight(startDate) == false) {
        startDate = date.writeOtherDateThanCurrent();
    }

    system("cls");
    cout << "Enter the ending date" << endl;
    endDate = date.writeOtherDateThanCurrent();
    while (date.isDateRight(endDate) == false) {
        endDate = date.writeOtherDateThanCurrent();
    }

    system("cls");
    if (startDate < endDate) {
        if (!incomes.empty()) {
            cout << ">>> DISPLAY BALANCE FOR SELECTED PERIOD <<<" << endl << endl;

            for (vector <Income>::iterator  itr = incomes.begin(); itr != incomes.end(); itr++) {
                if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                    int date = itr -> getDate();
                    if (date >= startDate && date <= endDate) {
                        sort(incomes.begin(), incomes.end(), sortIncomesByDate());
                        fileWithIncomes.displayIncome(*itr);
                        countTotalIncome(itr);
                    }
                }
            }
        }
        if (!expenses.empty()) {
            for (vector <Expense>::iterator  itr = expenses.begin(); itr != expenses.end(); itr++) {
                if (itr -> getUserId() == LOGGED_IN_USER_ID) {
                    int date = itr -> getDate();
                    if (date >= startDate && date <= endDate) {
                        sort(expenses.begin(), expenses.end(), sortExpensesByDate());
                        fileWithExpenses.displayExpense(*itr);
                        countTotalExpense(itr);
                    }
                }
            }
        }
        balanceOfIncomesAndExpenses();
    } else if (startDate > endDate) {
        cout << "Start date is later than end date" << endl << endl;
        system("pause");
    }

}



