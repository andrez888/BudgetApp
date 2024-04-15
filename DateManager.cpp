#include "DateManager.h"

void DateManager::calculateCurrentDate(map<string,int> &currentDate) {
    time_t currentTime = time(nullptr);

    tm* localTime = localtime(&currentTime);

    currentDate["year"] = localTime->tm_year + 1900; // Years since 1900
    currentDate["month"] = localTime->tm_mon + 1;    // Months start from 0
    currentDate["day"] = localTime->tm_mday;
}

bool DateManager::validateDate(string &date) {

    map<string,int> currentDate;
    int year,month,day;
    char dash1, dash2;
    stringstream ss(date);

    calculateCurrentDate(currentDate);

    if(date == "y" || date == "Y") {
        date = to_string(currentDate["year"]) + "-" + (currentDate["month"] < 10 ? "0" : "") + to_string(currentDate["month"]) + "-"
        + (currentDate["day"] < 10 ? "0" : "") + to_string(currentDate["day"]);
        cout << date;
        system("pause");
        return true;
    }

    if(date.length() != 10) {
        cout << "Incorrect date format. Try again" << endl;
        return false;
    }

    if (ss.fail() || !(ss >> year >> dash1 >> month >> dash2 >> day)) {
        cout << "Incorrect date format. Try again" << endl;
        return false; // Extraction failed
    }

    // Check if extraction was successful and separators are correct
    if (dash1 != '-' || dash2 != '-') {
        return false; // Invalid separators
    }

    if (year < 2000 || year > currentDate["year"]) {
        cout << "Invalid year. Try again" << endl;
        return false;
    }

    // Check if month is under or equal to current month and day is under or equal to current day
    if (month < 1 || month >12 || (year == currentDate["year"] && month > currentDate["month"])) {
        cout << "Invalid month. Try again" << endl;
        return false;
    }
    if((year == currentDate["year"] && month == currentDate["month"]) && day > currentDate["day"]  ) {
        cout << "Invalid day. Try again" << endl;
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
        // For all other months, ensure the day is not greater than 31
        cout << "Invalid day. Try again" << endl;
        return false;
        break;
    }

    return true; // Date is valid
}

bool DateManager::isYearLeap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
