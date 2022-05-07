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
