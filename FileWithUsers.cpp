#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user) {
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(getFileName().c_str(), ios::app);

    if (textFile.good()) {
        lineWithUserData = convertUserDataToLineWithDashes(user);

        if (isFileEmpty() == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData;
        }
        textFile.close();
    } else
        cout << "Nie udalo sie otworzyc pliku " << getFileName() << " i zapisac w nim danych." << endl;

}
string FileWithUsers::convertUserDataToLineWithDashes(User user) {
    string lineWithUserData = "";

    lineWithUserData += AuxiliaryMethods::convertIntToString(user.getId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}
vector <User> FileWithUsers::loadUsersFromFile() {
    User user;
    vector <User> users;
    string singleUserDataSeparatedByVerticalLines = "";
    fstream textFile;

    textFile.open(getFileName().c_str(), ios::in);

    if (textFile.good()) {
        while (getline(textFile, singleUserDataSeparatedByVerticalLines)) {
            user = getUserData(singleUserDataSeparatedByVerticalLines);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}
User FileWithUsers::getUserData(string singleUserDataSeparatedByVerticalLines) {
    User user;
    string singleUserData = "";
    int numberOfSingleDataOfUser = 1;

    for (int markPosition = 0; markPosition < singleUserDataSeparatedByVerticalLines.length(); markPosition++) {
        if (singleUserDataSeparatedByVerticalLines[markPosition] != '|') {
            singleUserData += singleUserDataSeparatedByVerticalLines[markPosition];
        } else {
            switch(numberOfSingleDataOfUser) {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberOfSingleDataOfUser++;
        }
    }
    return user;
}
