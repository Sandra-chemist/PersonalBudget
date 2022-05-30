#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

class AuxiliaryMethods {

public:
    static string convertIntToString(int number);
    static char loadChar();
    static string loadLine();
    static int convertStringToInt(string number);
    static float loadFloat();
    static string convertFloatToString(float number);
    static float convertStringToFloat(string amount);
    static string convertCommaToDot(string input);
    static float writeDownTwoDecimalPlaces(float number);
};
#endif
