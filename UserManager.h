#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include "User.h"
#include <vector>

using namespace std;

class UserManager {

    const int  LOGGED_IN_USER_ID;
    vector <User> users;

    User typeNewUserdata();
    int getNewUserId();

public:
    UserManager(int userID): LOGGED_IN_USER_ID(userID){
    }

    bool doesLoginExist(string login);
    void userLogin();
    void userRegistartion();
    void changePassword();
    bool isUserLoggedIn();
};

#endif
