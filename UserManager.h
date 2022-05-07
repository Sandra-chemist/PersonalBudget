#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"


using namespace std;

class UserManager {

  // FileWithUsers fileWithUsers;
    vector <User> users;
    User getNewUserData();
    int getNewUserId();
    bool loginExists(string login);

public:
    void registerUser();
};
#endif
