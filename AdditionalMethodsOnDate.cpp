#include "AdditionalMethodsOnDate.h"

string AdditionalMethodsOnDate::removeDashFromDate(string date) {
    string stringDateWithoutDash;
    for (int i = 0 ; i <= date.length(); i++) {
        if (date[i] != '-') {
            stringDateWithoutDash += date[i];
        }
    }
    return stringDateWithoutDash;
}
string AdditionalMethodsOnDate::addDashToDate(string date) {
    string stringDateWithDash;
    stringDateWithDash = date.insert (4,1,'-');
    stringDateWithDash = stringDateWithDash.insert (7,1,'-');
    return stringDateWithDash;
}

