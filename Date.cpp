#include "Date.h"

int Date::getCurrentDate() {
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
int Date::getCurrentYear() {
    year = nowLocal.tm_year+1900;
    cout << year << endl;
    return year;
}
int Date::getCurrentMonth() {
    month = nowLocal.tm_mon+1;
    cout << month << endl;
    return month;
}
int Date::getCurrentDay() {
    day = nowLocal.tm_mday;
    cout << day << endl;
    return day;
}
string Date::convertCurrentDateFromIntToString(int currentDate) {
    string dateAsString;
    dateAsString = AuxiliaryMethods::convertIntToString(currentDate);
    return dateAsString;
}
string Date::writeOtherDateThanCurrent() {

    cout << "Provide date in format YYYY-MM-DD: ";
    otherDate = AuxiliaryMethods::loadLine();

    cout << otherDate << endl;
    cout << "wprowadzony rok to: " << getYear() << endl;
    system("pause");
   // int yearAsInt;
 //   yearAsInt = AuxiliaryMethods::convertStringToInt(getYear());

   /* cout << endl;
    if (getYear() > 2000) {
        cout << "Rok jest wiekszy niz liczba 2000" << endl;
    } else {
        cout << "Rok jest mniejszy niz 2000" << endl;
    }*/

    Sleep(1000);
    getMonth();
    cout << endl;
    Sleep(1000);
    getDay();
    cout << endl;
    Sleep(1000);

    /* string otherDateWithoutDash;
     otherDateWithoutDash = AuxiliaryMethods::removeDashFromDate(otherDate);
     cout << otherDateWithoutDash << endl;
     Sleep (2000);*/
    return otherDate;
}
string Date::getYear() {
    int lengthOfOtherDate = otherDate.length();
    string year;
    for (int i = 0; i < lengthOfOtherDate - 6; i++) {
        year = otherDate[i];
        cout << year;
    }
    return year;
}
string Date::getMonth() {
    int lengthOfOtherDate = otherDate.length();
    string month;
    for (int i = 5; i < lengthOfOtherDate - 3; i++) {
        month = otherDate[i];
        cout << month;
    }
    return month;
}
string Date::getDay() {
    int lengthOfOtherDate = otherDate.length();
    string day;
    for (int i = 8; i < lengthOfOtherDate; i++) {
        day = otherDate[i];
        cout << day;
    }
    return day;
}

bool Date::isDateRight(string date) {

    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    if (isDateCorrect(date)) {
        return true;
    } else if (isYearCorrect(year)) {
        return true;
    } else if (isMonthCorrect(month)) {
        return true;
    } else if (day >= 1 && day <= 31) {
        if (isDayCorrect(day)) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }

    return true;
}
bool Date::isDateCorrect(string date)
{
if ((!date.size() == 10) || (!date[0] == 2) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}
bool Date::isYearCorrect(int year)
{
  int minValue = 2000;
  if (year < getCurrentYear() && year > minValue) {
        return true;
    }
    return false;
}
bool Date::isMonthCorrect(int month)
{
   if (month >= 1 && month <= 12) {
        return true;
    }
    return false;
}
bool Date::isDayCorrect(int day)
{

}




