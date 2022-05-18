#include "ExpenseManager.h"

void ExpenseManager::addExpense() {
    Expense expense;
    system("cls");
    cout << " >>> ADDING NEW EXPENSE <<<" << endl << endl;
    expense = provideDataOfNewExpense();
    expenses.push_back(expense);

    fileWithExpenses.addExpenseToFile(expense);
    cout << "New expense has been added" << endl;
}
Expense ExpenseManager::provideDataOfNewExpense() {
    Expense expense;
    string item;
    float amount;
    int currentDate;
    char choice;
    string otherDate;

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
        int otherDateAsInt = AuxiliaryMethods::convertStringToInt(otherDate);
        expense.setDate(otherDateAsInt);
    }
    cout << "Enter item of expense: ";
    item = AuxiliaryMethods::loadLine();
    expense.setItem(item);

    cout << "Enter amount of expense: ";
    amount = AuxiliaryMethods::loadFloat();
    expense.setAmount(amount);
    return expense;
}
int ExpenseManager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

