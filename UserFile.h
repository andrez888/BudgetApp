#ifndef USERFILE_H
#define USERFILE_H

#include "Markup.h"
#include <iostream>
#include <vector>
#include "User.h"

using namespace std;
class UserFile{
    const string FILE_NAME;

public:
    UserFile(string fileName) : FILE_NAME(fileName){
    }
    void addUserToFile(const User &user);
    vector <User> loadUsersFromFile();
    bool changePasswordInFile(int id, const string newPassword);
};
#endif
