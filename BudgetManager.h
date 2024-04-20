#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include "UserManager.h"
#include "TransactionManager.h"
#include "Utils.h"

using namespace std;

class  BudgetManager {
    UserManager userManager;
    TransactionManager *transactionManager;
    const string FILE_WITH_EXPENSES_NAME;
    const string FILE_WITH_INCOMES_NAME;

public:
    BudgetManager(string userFileName, string expensesFileName, string incomesFileName):
        userManager(userFileName), FILE_WITH_EXPENSES_NAME(expensesFileName), FILE_WITH_INCOMES_NAME(incomesFileName) {
        transactionManager = NULL;
    }
    ~BudgetManager() {
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
    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();
    void userLogOut();

};

#endif
