#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "IncomeManager.h"
#include "ExpenseManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    Date date;
    IncomeManager *incomeManager;
    ExpenseManager *expenseManager;
    const string FILE_NAME_WITH_INCOMES;
    const string FILE_NAME_WITH_EXPENSES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes, string fileNameWithExpenses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes), FILE_NAME_WITH_EXPENSES(fileNameWithExpenses) {
    };
    void registerUser();
    void loginUser();
    bool isUserLoggedIn();
    void changePasswordLoggedInUser();
    void logOutUser();

    char selectOptionFromMainMenu();
    char selectOptionFromUserMenu();
    void getCurrentDate();
    void writeOtherDateThanCurrent();

    void addIncome();
    void addExpense();

};
#endif
