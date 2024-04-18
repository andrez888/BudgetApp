#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <iostream>



using namespace std;
class DateManager {
   void static calculateCurrentDate(map<string,int> &currentDate);
    bool static isYearLeap(int year) ;
public:
    bool static validateDate(string &date);
    int static convertStringDateToInt(const string &dateString);
    string static convertIntDateToStringWithDashes(int dateInt);
    int static getCurrentDate();
    int static getCurrentMonthFirstDayDate();
    int static getPreviousMonthLastDayDate();
    int static getPreviousMonthFirstDayDate();
};
