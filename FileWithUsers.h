#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile {

   string fileNameWithUsers;
public:
    FileWithUsers(string fileNameWithUsers) : XmlFile(fileNameWithUsers) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();


};
#endif
