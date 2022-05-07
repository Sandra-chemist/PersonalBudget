#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile {

    string convertUserDataToLineWithDashes(User user);
    User getUserData(string singleUserDataSeparatedByVerticalLines);

public:
    FileWithUsers(string fileName) : TextFile(fileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();


};
#endif
