#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "IncomeManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    Date date;
    IncomeManager *incomeManager;
    const string FILE_NAME_WITH_INCOMES;

public:
    PersonalBudget(string fileNameWithUsers, string fileNameWithIncomes)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_INCOMES(fileNameWithIncomes) {
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

};
#endif
