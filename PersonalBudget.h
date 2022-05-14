#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "UserManager.h"
#include "AuxiliaryMethods.h"
#include "Date.h"
#include "Income.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    Date date;
    Income income;


public:
    PersonalBudget(string fileNameWithUsers)
        : userManager(fileNameWithUsers) {
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
