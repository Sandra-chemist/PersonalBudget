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

    // lineWithUserData += MetodyPomocnicze::konwersjaIntNaString(uzytkownik.pobierzId())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}
