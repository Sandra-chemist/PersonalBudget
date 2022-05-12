#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

#include "AuxiliaryMethods.h"

using namespace std;

class Date {

    time_t now;
    struct tm nowLocal;
    int day;
    int month;
    int year;
    int currentDate;

public:
    int getCurrentDate();
    string writeOtherDateThanCurrent();
    string convertCurrentDateFromIntToString(int currentDate);
    bool isDateCorrect(string otherDate);
};
#endif
