#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "TransactionManager.h"
#include "Utils.h"

using namespace std;

class  BudgetManager{
    UserManager userManager;
    TransactionManager *transactionManager;

public:
    BudgetManager(string fileName): userManager(fileName){
        transactionManager = NULL;
    }
    ~BudgetManager(){
        delete transactionManager;
        transactionManager = NULL;
    }
    char chooseOptionFromUserMenu();
    char chooseOptionFromTransactionManager();
    void loginUser();
    void registrationUser();
    bool isUserLoggedIn();
     void addNewExpense();
    void addNewIncome();
};

#endif
