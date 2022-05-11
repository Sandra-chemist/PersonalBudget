#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

class AuxiliaryMethods {
public:

    static string convertIntToString(int number);
    static char loadChar();
    static string loadLine();
    int converStringToInt (string date);

};
#endif
