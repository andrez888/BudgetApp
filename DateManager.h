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
    /*int convertStringDateToInt(const string &dateAsString) ;
    string getCurrentDate() ;
    int convertIntDateToStringWithDashes(int dateAsInt);
    int getCurrentDate() ;
    int getCurrentMonthFirstDayDate() ;
    int getPreviousMonthLastDayDate() ;
    int getPreviousMonthFirstDayDate() ;
*/
};
