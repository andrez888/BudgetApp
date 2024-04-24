#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "User.h"
#include <vector>
#include "UserFile.h"
#include "Utils.h"

using namespace std;

class UserManager {
    UserFile userFile;
    int  loggedInUserId;
    vector <User> users;

    User typeNewUserdata();
    int getNewUserId();
    bool doesLoginExist(string login);

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedInUserId = 0;
        users = userFile.loadUsersFromFile();
    }


    void userLogin();
    void userRegistartion();
    bool isUserLoggedIn();
    void showVector();
    int getLoggedInUserId();
    void userLogOut();
    void changePassword();
};

#endif
