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

    cout << currentDate << endl;
    cout << nowLocal.tm_mday << "-" << nowLocal.tm_mon+1 << "-" << nowLocal.tm_year+1900 << endl;
    Sleep (10000);
    return currentDate;
}
