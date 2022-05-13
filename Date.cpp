#include "Date.h"

int Date::getCurrentDate() {
    time_t now;
    now = time(NULL);
    nowLocal = *localtime (&now);

    year = nowLocal.tm_year+1900;
    currentDate = (year * 10000);
    month = nowLocal.tm_mon+1;
    currentDate += (month * 100);
    day = nowLocal.tm_mday;
    currentDate += day;

    cout << currentDate << endl;
    cout << nowLocal.tm_year+1900 << "-" << nowLocal.tm_mon+1 << "-" << nowLocal.tm_mday << endl;

    getCurrentYear();
     getCurrentMonth();
      getCurrentDay();

    Sleep (2000);
    return currentDate;
}
int Date::getCurrentYear()
{
    year = nowLocal.tm_year+1900;
    cout << year << endl;
    return year;
}
int Date::getCurrentMonth()
{
    month = nowLocal.tm_mon+1;
    cout << month << endl;
    return month;
}
int Date::getCurrentDay()
{
    day = nowLocal.tm_mday;
    cout << day << endl;
    return day;
}
