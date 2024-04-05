#include <iostream>
#include "BudgetManager.h"
#include "User.h"
#include <vector>


using namespace std;

int main()
{
    BudgetManager budgetManager("users.xml");
    char choice;

    while(1){
        if(!budgetManager.isUserLoggedIn()){
            choice = budgetManager.chooseOptionFromUserMenu();
        switch(choice){
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
    }else{
        choice = budgetManager.chooseOptionFromTransactionManager();
        switch(choice){
        case '1':

            break;
        case '2':

            break;
        case '3':

            break;
             case '4':

            break;
            case '5':

            break;
        case '6':
            exit(0);
            break;
            case '7':

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
