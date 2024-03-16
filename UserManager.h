#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "User.h"
#include <vector>
#include "UserFile.h"

using namespace std;

class UserManager {
    UserFile userFile;
    int  loggedInUserId;
    vector <User> users;

    User typeNewUserdata();
    int getNewUserId();

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedInUserId = 0;
    }

    bool doesLoginExist(string login);
    void userLogin(vector <User>& users);
    void userRegistartion(vector <User> &users);
    void changePassword();
    bool isUserLoggedIn();
};

#endif
