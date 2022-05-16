#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntToString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
char AuxiliaryMethods::loadChar() {
    string entry = "";
    char mark  = {0};

    while (true) {
        getline(cin, entry);

        if (entry.length() == 1) {
            mark = entry[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return mark;
}
string AuxiliaryMethods::loadLine() {
    string entry = "";
    getline(cin, entry);
    return entry;
}
int AuxiliaryMethods::convertStringToInt(string number) {
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}
string AuxiliaryMethods::removeDashFromDate(string date) {

    string stringDateWithoutDash;

    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            stringDateWithoutDash += date[i];
        }
    }
    return stringDateWithoutDash;
}
float AuxiliaryMethods::loadFloat() {
    float amount;
    cin >> amount;
    return amount;
}
string AuxiliaryMethods::convertFloatToString(float number) {
    stringstream floatToStr;
    string str;

    floatToStr << number;
    floatToStr >> str;
    floatToStr.clear();
    cout << str;
    return str;
}
string AuxiliaryMethods::addDashToDate(string date) {

    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');
    cout << stringDateWithDash << endl;

    return stringDateWithDash;
}
