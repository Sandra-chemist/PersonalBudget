#include "UserManager.h"

void UserManager::registerUser() {
    User user = getNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "The account created successfully" << endl << endl;
    system("pause");
}
User UserManager::getNewUserData() {
    User user;

    user.setUserId(getNewUserId());
    string name, surname;
    cout << "Enter your name: ";
    cin>> name;
    user.setName(name);
    cout << "Enter your surname: ";
    cin>> surname;
    user.setSurname(surname);
    string login;
    do {
        cout << "Enter your login: ";
        cin >> login;
        user.setLogin(login);
    } while (loginExists(user.getLogin()) == true);

    string password;
    cout << "Enter your password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}
int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}
bool UserManager::loginExists(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "This login is unavailable." << endl;
            return true;
        }
    }
    return false;
}
void UserManager::loginUser() {
    string login = "", password = "";

    cout << endl << "Enter your login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Enter your password. Number of attempts: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "You have logged in successfully" << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Incorrect password entered 3 times" << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "User does not exist" << endl << endl;
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
    cout << "Enter your new password: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getUserId() == loggedInUserId) {
            users[i].setPassword(newPassword);
            cout << "Your password has been changed" << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}
void UserManager::logOutUser() {
    loggedInUserId = 0;
    cout << "You have been logged out successfully" << endl;
    system("pause");
}
int UserManager::getLoggedInUserId() {
    return loggedInUserId;
}


