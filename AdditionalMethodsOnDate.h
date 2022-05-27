#ifndef ADDITIONALMETHODSONDATE_H
#define ADDITIONALMETHODSONDATE_H

#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

class AdditionalMethodsOnDate {

public:
    static string removeDashFromDate(string date);
    static string addDashToDate(string date);

};
#endif
