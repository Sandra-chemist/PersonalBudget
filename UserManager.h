#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserManager {

    int loggedInUserId;
    FileWithUsers fileWithUsers;
    vector <User> users;
    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    UserManager(string fileNameWithUsers) : fileWithUsers(fileNameWithUsers) {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void registerUser();
    void loginUser();
    bool isUserLoggedIn();
    void changePasswordLoggedInUser();
    void logOutUser();
    int getLoggedInUserId();

};
#endif
