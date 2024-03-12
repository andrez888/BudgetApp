#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

class UserManager {

    int  loggedInUserId;
    vector <User> users;

    User typeNewUserdata();
    int getNewUserId();

public:
    UserManager() {
        loggedInUserId = 0;
    }

    bool doesLoginExist(string login);
    void userLogin(vector <User>& users);
    void userRegistartion(vector <User> &users);
    void changePassword();
    bool isUserLoggedIn();
};

#endif
