#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main() {
    char choice;
    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

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
        } else {
            if (personalBudget.isUserLoggedIn())

                // personalBudget.getCurrentDate();
                //  personalBudget.writeOtherDateThanCurrent();
                 personalBudget.showAllIncomesForCurrentMonth();
                choice = personalBudget.selectOptionFromUserMenu();

        }
        switch (choice) {
        case '1':
            personalBudget.addIncome();
            break;
        case '2':
          personalBudget.addExpense();
            break;
        /* case '3':
             personalBudget.wyszukajAdresatowPoNazwisku();
             break;
         case '4':
             personalBudget.wyswietlWszystkichAdresatow();
             break;
         case '5':
            personalBudget.usunAdresata();
             break;*/
        case '6':
            personalBudget.changePasswordLoggedInUser();
            break;
        case '7':
            personalBudget.logOutUser();
            break;
        }
    }

    return 0;
}
