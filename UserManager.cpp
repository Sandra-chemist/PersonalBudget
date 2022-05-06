#include "UserManager.h"

void UserManager::registerUser() {
   User user = getNewUserData();

   users.push_back(user);
  //  plikZUzytkownikami.dopiszUzytkownikaDoPliku(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
User UserManager::getNewUserData() {
    User user;

    user.setId(getNewUserId());
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
