#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class  BudgetManager{
    UserManager userManager;

public:
    BudgetManager(string fileName): userManager(fileName){

    }
    char chooseOptionFromUserMenu();
    char chooseOptionFromBudgetBook();
    void loginUser();
    void registrationUser();
    bool isUserLoggedIn();
};

#endif
