#include "Date.h"

int Date::getCurrentDate() {

    now = time(NULL);

    nowLocal = *localtime (&now);

    year = nowLocal.tm_year+1900;
    currentDate = (year*1000);
    month = nowLocal.tm_mon+1;
    currentDate += (month*100);
    day = nowLocal.tm_mday;
    currentDate += day;

   // cout << currentDate << endl;
   // cout << nowLocal.tm_mday << "-" << nowLocal.tm_mon+1 << "-" << nowLocal.tm_year+1900 << endl;
   // Sleep (5000);
    return currentDate;
}
string Date::convertCurrentDateFromIntToString(int currentDate)
{
    string dateAsString;
    dateAsString = AuxiliaryMethods::convertIntToString(currentDate);
    Sleep (5000);
    return dateAsString;
}
string Date::writeOtherDateThanCurrent()
{
     string otherDate;
     cout << "Provide date in format YYYY-MM-DD: ";
     otherDate = AuxiliaryMethods::loadLine();
     cout << otherDate << endl;
     Sleep (2000);

     string otherDateWithoutDash;
     otherDateWithoutDash = AuxiliaryMethods::removeDashFromDate(otherDate);
     cout << otherDateWithoutDash << endl;
     Sleep (2000);

     return otherDate;
}

