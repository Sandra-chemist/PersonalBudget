#include "ExpenseManager.h"

Expense ExpenseManager::provideDataOfNewExpense() {
    Expense expense;
    string item;
    float amount;
    int currentDate;
    char choice;
    string dateAsString, dateAsStringWithDash, otherDate;

    expense.setExpenseId(getNewExpenseId());
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Do you want to add expense with current date?" << endl << endl;
    cout << "If yes, enter '1',if you want to choose different date - enter '2'." << endl;
    choice = AuxiliaryMethods::loadChar();

    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    if (choice == '1') {
        currentDate = date.getCurrentDate();
        dateAsString = AuxiliaryMethods::convertIntToString(currentDate);
        dateAsStringWithDash = AuxiliaryMethods::addDashToDate(dateAsString);
        expense.setDate(dateAsStringWithDash);
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
    amount = AuxiliaryMethods::loadFloat();
    expense.setAmount(amount);
    return expense;
}
