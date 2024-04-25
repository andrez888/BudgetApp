#ifndef USERFILE_H
#define USERFILE_H

#include "Markup.h"
#include <iostream>
#include <vector>
#include "User.h"
#include "File.h"

using namespace std;
class UserFile : public File{
public:
    UserFile(string fileName) : File(fileName){
    }
    void addUserToFile(const User &user);
    vector <User> loadUsersFromFile();
    bool changePasswordInFile(int id, const string newPassword);
};
#endif
