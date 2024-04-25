#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <map>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <regex>

using namespace std;
class DateManager {
    static void  calculateCurrentDate(map<string,int> &currentDate);
    static bool  isYearLeap(int year) ;
public:
    static bool  validateDate(string &date);
    static int  convertStringDateToInt(const string &dateString);
    static string  convertIntDateToStringWithDashes(int dateInt);
    static int  getCurrentDate();
    static int  getCurrentMonthFirstDayDate();
    static int  getPreviousMonthLastDayDate();
    static int  getPreviousMonthFirstDayDate();
};
#endif
