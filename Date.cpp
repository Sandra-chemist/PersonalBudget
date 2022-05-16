#include "Date.h"

int Date::getCurrentDate() {
    year = getCurrentYear();
    currentDate = (year * 10000);
    month = getCurrentMonth();
    currentDate += (month * 100);
    day = getCurrentDay();
    currentDate += day;

    return currentDate;
}
int Date::getCurrentYear() {
    time(&now);
    nowLocal = localtime(&now);
    year = nowLocal -> tm_year+1900;
  //  cout << year << endl;
    return year;
}
int Date::getCurrentMonth() {
    time(&now);
    nowLocal = localtime(&now);
    month = nowLocal -> tm_mon+1;
  //  cout << month << endl;
    return month;
}
int Date::getCurrentDay() {
    time(&now);
    nowLocal = localtime(&now);
    day = nowLocal -> tm_mday;
  //  cout << day << endl;
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
    system("pause");

    cout << "getYear(): "<< getYear() << endl;
    int yearAsInt;
    yearAsInt = AuxiliaryMethods::convertStringToInt(getYear());
    cout <<  yearAsInt << endl;

    cout << "getMonth(): "<< getMonth() << endl;
    int monthAsInt;
    monthAsInt = AuxiliaryMethods::convertStringToInt(getMonth());
    cout <<  monthAsInt << endl;

    cout << "getDay(): "<< getDay() << endl;
    int dayAsInt;
    dayAsInt = AuxiliaryMethods::convertStringToInt(getDay());
    cout <<  dayAsInt << endl;


    if (isYearCorrect(yearAsInt))
    {
        cout << "Rok jest poprawnie wpisany" << endl;
    }
    else
    {
        cout << "Rok jest niepoprawny" << endl;
    }

          system("pause");


    /* string otherDateWithoutDash;
     otherDateWithoutDash = AuxiliaryMethods::removeDashFromDate(otherDate);
     cout << otherDateWithoutDash << endl;
     Sleep (2000);*/
    return otherDate;
}
/*bool Date::isDateRight(string otherDate) {

    int year = (otherDate[0]-'0')*1000 + (otherDate[1]-'0')*100 + (otherDate[2]-'0')*10 + (otherDate[3]-'0');
    int month = (otherDate[5]-'0')*10 + (otherDate[6]-'0');
    int day = (otherDate[8]-'0')*10 + (otherDate[9]-'0');

    if (isDateCorrect(otherDate) == true) {
        return true;
    } else if (isYearCorrect(year) == true) {
        return true;
    } else if (isMonthCorrect(month) == true) {
        return true;
    } else if (isDayCorrect(day, month) == true) {
        return true;
    } else {
        return false;
    }

return true;
}*/
string Date::getYear() {
    int lengthOfOtherDate = otherDate.length();
    string year;
    for (int i = 0; i < lengthOfOtherDate - 6; i++) {
        year += otherDate[i];
    }
    return year;
}
string Date::getMonth() {
    int lengthOfOtherDate = otherDate.length();
    string month;
    for (int i = 5; i < lengthOfOtherDate - 3; i++) {
        month += otherDate[i];
    }
    return month;
}
string Date::getDay() {
    int lengthOfOtherDate = otherDate.length();
    string day;
    for (int i = 8; i < lengthOfOtherDate; i++) {
        day += otherDate[i];
    }
    return day;
}
bool Date::isDateCorrect(string date) {
    if ((!date.size() == 10) || (!date[0] == 2) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}
bool Date::isYearCorrect(int year) {
    int minValue = 2000;
    if (year <= getCurrentYear() && year > minValue) {
        return true;
    } else {
        return false;
    }
}
bool Date::isMonthCorrect(int month) {
    if (month >= 1 && month <= 12) {
        return true;
    }
    else
    {
          return false;
    }
}
bool Date::isDayCorrect(int day, int month) {

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day >= 1 && day <= 31) {
            return true;
        } else {
            return false;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day >= 1 && day <= 30) {
            return true;
        } else {
            return false;
        }
    } else if (month == 2) {
        if (day >= 1 && day <= 28) {
            return true;
        } else {
            return false;
        }
    }
}





