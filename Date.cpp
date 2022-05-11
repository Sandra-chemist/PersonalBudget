#include "Date.h"

int Date::getCurrentDate() {
    time_t now;
    struct tm nowLocal;
    now = time(NULL);

    nowLocal = *localtime (&now);

    cout << nowLocal.tm_mday << "-" << nowLocal.tm_mon+1 << "-" << nowLocal.tm_year+1900 << endl;
    Sleep (1000);
    return now;
}
