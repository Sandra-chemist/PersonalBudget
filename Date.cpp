#include "Date.h"

int Date::getCurrentDate() {
    time_t now;
    struct tm nowLocal;
    now = time(NULL);

    nowLocal = *localtime (&now);

    year = nowLocal.tm_year+1900;
    currentDate = (year * 10000);
    month = nowLocal.tm_mon+1;
    currentDate += (month * 100);
    day = nowLocal.tm_mday;
    currentDate += day;

    cout << currentDate << endl;
    cout << nowLocal.tm_year+1900 << "-" << nowLocal.tm_mon+1 << "-" << nowLocal.tm_mday<< endl;
    Sleep (2000);
    return currentDate;
}
