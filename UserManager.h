#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class UserManager{

 vector <User> users;
     User getNewUserData();
     int getNewUserId();
bool loginExists(string login);
 public:
     UserManager();
     void registerUser();
};
#endif
