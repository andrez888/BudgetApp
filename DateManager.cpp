#include "DateManager.h"

void DateManager::calculateCurrentDate(map<string,int> &currentDate) {
    time_t currentTime = time(nullptr);

    tm* localTime = localtime(&currentTime);

    currentDate["year"] = localTime->tm_year + 1900;
    currentDate["month"] = localTime->tm_mon + 1;
    currentDate["day"] = localTime->tm_mday;
}

bool DateManager::validateDate(string &date) {

    map<string, int> currentDate;
    int year, month, day;

    calculateCurrentDate(currentDate);

    if(date == "y" || date == "Y") {
        date = to_string(currentDate["year"]) + "-" + (currentDate["month"] < 10 ? "0" : "") + to_string(currentDate["month"]) + "-"
               + (currentDate["day"] < 10 ? "0" : "") + to_string(currentDate["day"]);
        return true;
    }

    if(date.length() != 10) {
        cout << "Incorrect date format. Try again" << endl;
        return false;
    }

    regex pattern("[0-9]{4}-[0-9]{2}-[0-9]{2}");

    if (!regex_match(date, pattern)) {
        cout << "Incorrect date format. Try again" << endl;
        return false;
    }

    try {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }

    if (year < 2000 || year > currentDate["year"]) {
        cout << "Invalid year. Try again" << endl;
        return false;
    }

    if (month < 1 || month >12 || (year == currentDate["year"] && month > currentDate["month"])) {
        cout << "Invalid month. Try again" << endl;
        return false;
    }

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31 ) {
            cout << "Invalid day. Try again" << endl;
            return false;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30) {
            cout << "Invalid day. Try again" << endl;
            return false;
        }
        break;
    case 2:
        if(isYearLeap(year)) {
            if(day > 29) {
                cout << "Invalid day. Try again" << endl;
                return false;
            }
        } else {
            if(day > 28) {
                cout << "Invalid day. Try again" << endl;
                return false;
            }
        }
        break;
    default:
        cout << "Invalid day. Try again" << endl;
        return false;
        break;
    }

    return true;
}

bool DateManager::isYearLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int DateManager::convertStringDateToInt(const string &dateString) {
    string dateWithoutDash;
    int dateInt;

    for (char c : dateString) {
        if (c != '-') {
            dateWithoutDash += c;
        }
    }
    dateInt = stoi(dateWithoutDash);

    return dateInt;
}

string DateManager:: convertIntDateToStringWithDashes(int dateInt) {

    string dateStrWithDashes = to_string(dateInt);
    dateStrWithDashes.insert(4,"-");
    dateStrWithDashes.insert(7,"-");

    return dateStrWithDashes;
}

int DateManager::getCurrentDate() {

    int currentDateInt;
    map<string,int> currentDate;

    calculateCurrentDate(currentDate);

    currentDateInt = currentDate["year"] * 10000 + currentDate["month"] * 100 + currentDate["day"];

    return currentDateInt;
}

int DateManager::getCurrentMonthFirstDayDate() {

    int currentMonthFirstDayDate;
    map<string,int> currentDate;
    int firstDay = 1;

    calculateCurrentDate(currentDate);

    currentMonthFirstDayDate = currentDate["year"] * 10000 + currentDate["month"] * 100 + firstDay;

    return currentMonthFirstDayDate;
}

int DateManager:: getPreviousMonthLastDayDate() {

    int previousYear, previousMonth, lastDay;
    int previousMonthLastDayDate;
    map<string,int> currentDate;

    calculateCurrentDate(currentDate);

    previousYear = currentDate["year"];
    previousMonth = currentDate["month"] - 1;

    if(previousMonth == 0) {
        previousMonth = 12;
        previousYear--;
    }

    if (previousMonth == 2) {
        if (isYearLeap(previousYear))
            lastDay = 29;
        else
            lastDay = 28;
    } else if (previousMonth == 4 || previousMonth == 6 || previousMonth == 9 || previousMonth == 11) {
        lastDay = 30;
    } else {
        lastDay = 31;
    }

    previousMonthLastDayDate = previousYear *10000 + previousMonth * 100 + lastDay;

    return previousMonthLastDayDate;
}

int DateManager::getPreviousMonthFirstDayDate() {

    int previousYear, previousMonth, firstDay;
    int previousMonthFirstDayDate;
    map<string,int> currentDate;

    calculateCurrentDate(currentDate);

    previousYear = currentDate["year"];
    previousMonth = currentDate["month"] - 1;
    firstDay = 1;

    if(previousMonth == 0) {
        previousMonth = 12;
        previousYear--;
    }

    previousMonthFirstDayDate = previousYear *10000 + previousMonth * 100 + firstDay;

    return previousMonthFirstDayDate;
}
