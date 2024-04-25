#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>

using namespace std;
class Utils {
public:
    static string readLine();
    static char getCharacter();
    static bool validateAmount(string &amount);
};
#endif
