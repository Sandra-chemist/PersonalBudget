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
    cout << year << endl;
    return year;
}
int Date::getCurrentMonth() {
    time(&now);
    nowLocal = localtime(&now);
    month = nowLocal -> tm_mon+1;
    cout << month << endl;
    return month;
}
int Date::getCurrentDay() {
    time(&now);
    nowLocal = localtime(&now);
    day = nowLocal -> tm_mday;
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
//    cout << "wprowadzony rok to: " << getYear() << endl;
    system("pause");
    // int yearAsInt;
//   yearAsInt = AuxiliaryMethods::convertStringToInt(getYear());

    /* cout << endl;
     if (getYear() > 2000) {
         cout << "Rok jest wiekszy niz liczba 2000" << endl;
     } else {
         cout << "Rok jest mniejszy niz 2000" << endl;
     }*/

   /* Sleep(1000);
    getMonth();
    cout << endl;
    Sleep(1000);
    getDay();
    cout << endl;
    Sleep(1000);*/

    if (isYearCorrect(year) == true)
    {
        cout << "Data jest poprawnie wpisana" << endl;

    }
    else cout << "Rok jest niepoprawny" << endl;

          system("pause");


    /* string otherDateWithoutDash;
     otherDateWithoutDash = AuxiliaryMethods::removeDashFromDate(otherDate);
     cout << otherDateWithoutDash << endl;
     Sleep (2000);*/
    return otherDate;
}
bool Date::isDateRight(string date) {

    int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int month = (date[5]-'0')*10 + (date[6]-'0');
    int day = (date[8]-'0')*10 + (date[9]-'0');

    if (isDateCorrect(date) == true) {
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
}
bool Date::isDateCorrect(string date) {
    if ((!date.size() == 10) || (!date[0] == 2) || (date[4] != '-') || (date[7] != '-'))
        return false;
    else
        return true;
}
bool Date::isYearCorrect(int year) {
    int minValue = 2000;
    if (year < getCurrentYear() && year > minValue) {
        return true;
    }
    return false;
}
bool Date::isMonthCorrect(int month) {
    if (month >= 1 && month <= 12) {
        return true;
    }
    return false;
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





