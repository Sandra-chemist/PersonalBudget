#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
//#include "MetodyPomocnicze.h"
#include "TextFile.h"

using namespace std;

class FileWithUsers : public TextFile {

    void addUserToFile(User user);
    string convertUserDataToLineWithDashes(User user);
};
#endif
