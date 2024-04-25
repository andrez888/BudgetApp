#ifndef FILE_H
#define FILE_H

#include "Markup.h"

using namespace std;
class File {
    const string FILE_NAME;

public:
    File(string fileName) : FILE_NAME(fileName) {
    }

    string getFileName();
};
#endif
