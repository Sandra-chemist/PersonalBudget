#include <iostream>

#include "PersonalBudget.h"
#include "UserManager.h"

using namespace std;

int main() {
    char choice;
    PersonalBudget personalBudget("Uzytkownicy.txt");


    choice = personalBudget.selectOptionFromMainMenu();
    switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
         /*   case '2':
                 personalBudget.logInUser();
                break;*/
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }



    return 0;
}
