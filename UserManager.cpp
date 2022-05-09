#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());
    string name, surname;
    cout << "Podaj imie: ";
    cin>> name;
    user.setName(name);
    cout << "Podaj nazwisko: ";
    cin>> surname;
    user.setSurname(surname);
    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}
int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}
bool UserManager::loginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}
void UserManager::loginUser() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}
bool UserManager::isUserLoggedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}
void UserManager::changePasswordLoggedInUser() {
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == loggedInUserId) {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
   // plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(users);
}

