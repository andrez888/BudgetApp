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

    cin >> choice;

    return choice;
 }
 char BudgetManager::chooseOptionFromBudgetBook(){
 }
 void BudgetManager::loginUser(){
    userManager.userLogin();
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
