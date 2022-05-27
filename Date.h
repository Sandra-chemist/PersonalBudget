#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

#include "AuxiliaryMethods.h"
#include "AdditionalMethodsOnDate.h"

using namespace std;

class Date {
    time_t now;
    struct tm *nowLocal;
    int day, month, year;
    int currentDate;
    string otherDate;

    int getCurrentYear();
    int getCurrentMonth();
    int getCurrentDay();

    string getYear();
    string getMonth();
    string getDay();

    bool isDateCorrect(string date);
    bool isYearCorrect(int date);
    bool isMonthCorrect(int month);
    bool isDayCorrect(int day, int month, int year);

public:
    int getCurrentDate();
    int writeOtherDateThanCurrent();
    bool isDateRight(int date);
    bool isLeapYear(int year);
};
#endif
