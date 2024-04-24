#include <iostream>
#include "BudgetManager.h"

using namespace std;

int main() {
    BudgetManager budgetManager("users.xml", "expenses.xml", "incomes.xml");
    char choice;

    while(1) {
        if(!budgetManager.isUserLoggedIn()) {
            choice = budgetManager.chooseOptionFromUserMenu();
            switch(choice) {
            case '1':
                budgetManager.loginUser();
                break;
            case '2':
                budgetManager.registrationUser();
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << "Incorrect choice" <<endl;
                system("pause");
                break;
            }
        } else {
            choice = budgetManager.chooseOptionFromTransactionManager();
            switch(choice) {
            case '1':
                budgetManager.addNewIncome();
                break;
            case '2':
                budgetManager.addNewExpense();
                break;
            case '3':
                budgetManager.showCurrentMonthBalance();
                break;
            case '4':
                budgetManager.showPreviousMonthBalance();
                break;
            case '5':
                budgetManager.showSelectedPeriodBalance();
                break;
            case '6':
                budgetManager.changePassword();
                break;
            case '7':
                budgetManager.userLogOut();
                break;
            default:
                cout << "Incorrect choice" <<endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
