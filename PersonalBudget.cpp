#include "PersonalBudget.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
}
char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MAIN  MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Registration" << endl;
    cout << "2. Login" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}
void PersonalBudget::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
            financeManager = new FinanceManager(userManager.getLoggedInUserId(), FILE_NAME_WITH_INCOMES, FILE_NAME_WITH_EXPENSES);
       // incomeManager = new IncomeManager (FILE_NAME_WITH_INCOMES, userManager.getLoggedInUserId());
       // expenseManager = new ExpenseManager (FILE_NAME_WITH_EXPENSES, userManager.getLoggedInUserId());
    }
}
bool PersonalBudget::isUserLoggedIn() {
    userManager.isUserLoggedIn();
}
char PersonalBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance for current month" << endl;
    cout << "4. Display balance for previous month" << endl;
    cout << "5. Display balance for selected month" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out user" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}
void PersonalBudget::changePasswordLoggedInUser() {
    userManager.changePasswordLoggedInUser();
}
void PersonalBudget::logOutUser() {
    userManager.logOutUser();
}
void PersonalBudget::getCurrentDate() {
    date.getCurrentDate();
}
void PersonalBudget::writeOtherDateThanCurrent() {
    date.writeOtherDateThanCurrent();
}
void PersonalBudget::addIncome() {
    if (userManager.isUserLoggedIn()) {
        financeManager -> addIncome();
    }
}
void PersonalBudget::addExpense() {
    if (userManager.isUserLoggedIn()) {
        financeManager -> addExpense();
    }
}
void PersonalBudget::showAllIncomesForCurrentMonth() {
    if (userManager.isUserLoggedIn()) {
        financeManager -> showAllIncomesForCurrentMonth();
    }
}
void PersonalBudget::showAllExpensesForCurrentMonth() {
    if (userManager.isUserLoggedIn()) {
        financeManager -> showAllExpensesForCurrentMonth();
    }
}


