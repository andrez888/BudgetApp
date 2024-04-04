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
        if(1){
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
    }
    }

    return 0;
}
