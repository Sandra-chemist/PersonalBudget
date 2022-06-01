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
        cout << "It is not a single character. Enter again" << endl;
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
    return str;
}
float AuxiliaryMethods::convertStringToFloat(string str) {
    float num_float = stof(str);
    return num_float;
}
string AuxiliaryMethods::convertCommaToDot(string input) {
    size_t foundComma = input.find(",");
    if(foundComma != string::npos) {
        input.replace(foundComma, 1, ".");
    }
    return input;
}
bool AuxiliaryMethods::calculatePlaceAfterComma(string amount){

    int lengthAmount = amount.length();
    size_t foundComma = amount.find(".");
    int decimalAmount =  lengthAmount - (foundComma+1);
    if (decimalAmount <= 2)
    {
       return true;
    }
    else
    {
        cout << endl;
        cout << "The amount cannot have more than two decimal places." << endl;
        return false;
    }
}
string AuxiliaryMethods::addZeroAfterComma(float amount){
 stringstream ss;
    ss.setf(ios_base::fixed);
    ss.precision(2);
    ss<<amount;
    string s = ss.str();
    return s;
}
