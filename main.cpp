#include <iostream>

#include "PersonalBudget.h"
#include "UserManager.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Uzytkownicy.txt");

    personalBudget.registerUser();


    return 0;
}
