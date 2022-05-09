#include <iostream>

#include "PersonalBudget.h"
#include "UserManager.h"

using namespace std;

int main() {
    char choice;
    PersonalBudget personalBudget("Uzytkownicy.xml");

    choice = personalBudget.selectOptionFromMainMenu();

       while (true) {
        if (!personalBudget.isUserLoggedIn()) {
            choice = personalBudget.selectOptionFromMainMenu();

    switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
           case '2':
                 personalBudget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }else {
            if (personalBudget.isUserLoggedIn())

                choice = personalBudget.selectOptionFromUserMenu();
       }
       }

    return 0;
}
