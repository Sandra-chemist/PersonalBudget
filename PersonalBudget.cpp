#include "PersonalBudget.h"

void PersonalBudget::registerUser() {
    userManager.registerUser();
}
char PersonalBudget::selectOptionFromMainMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadChar();

    return choice;
}
void PersonalBudget::loginUser() {
    userManager.loginUser();
    if (userManager.isUserLoggedIn()) {
        incomeManager = new IncomeManager (FILE_NAME_WITH_INCOMES);
    }
}
bool PersonalBudget::isUserLoggedIn() {
    userManager.isUserLoggedIn();
}
char PersonalBudget::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
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
    cout << "Twoj wybor: ";
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
        incomeManager->addIncome();
    }
}



