#include "BudgetManager.h"

 char BudgetManager::chooseOptionFromUserMenu(){
    system("cls");

    char choice;
    cout << "____________MENU____________" << endl;
    cout << "---------------------------------------------- " << endl;
    cout <<"1.Login user" << endl;
    cout << "2.Registartion user" <<endl;
    cout <<"3.Quit" << endl;
    cout <<"Your choice: " << endl;

    choice = Utils::getCharacter();

    return choice;
 }
 char BudgetManager::chooseOptionFromTransactionManager(){
     system("cls");

    char choice;
    cout << "___________Budget book_____________" << endl;
    cout << "---------------------------------------------- " << endl;
    cout <<"1. Add new income" << endl;
    cout <<"2. Add new expense" << endl;
    cout << "3. Show balance from previous month" <<endl;
    cout << "4. Show balance from current month" <<endl;
    cout <<"5. Show balance from selected period" << endl;
    cout <<"6. Change password " << endl;
    cout <<"7. Log out" << endl;
    cout <<"Your choice: " << endl;

    choice = Utils::getCharacter();

    return choice;
 }
void BudgetManager::loginUser(){
    userManager.userLogin();
    if(userManager.isUserLoggedIn()){
        transactionManager = new TransactionManager(userManager.getLoggedInUserId(), FILE_WITH_EXPENSES_NAME, FILE_WITH_INCOMES_NAME);
    }
 }

void BudgetManager::registrationUser(){
    userManager.userRegistartion();
}

bool BudgetManager::isUserLoggedIn(){
    if(userManager.isUserLoggedIn()){
        return true;
    }else{
        return false;
    }
}

void BudgetManager::addNewExpense(){
    transactionManager->addNewExpense();
}

void BudgetManager::addNewIncome(){
    transactionManager->addNewIncome();
}
