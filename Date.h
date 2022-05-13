#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

class Date {

    int currentDate;
    int year;
    int month;
    int day;

public:
    int getCurrentDate();
};
#endif
