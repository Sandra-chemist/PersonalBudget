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
    static int convertStringToInt (string number);
    static string removeDashFromDate(string date);
    static float loadFloat();
    static string convertFloatToString(float number);
    static string addDashToDate(string date);

};
#endif
