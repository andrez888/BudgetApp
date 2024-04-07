#include "TransactionManager.h"

void TransactionManager::addNewExpense(){
    Transaction transaction;

    system("cls");
    cout << "...Adding new expense..." << endl;
    transaction = typeNewExpense();

    expenses.push_back(transaction);
}

void TransactionManager::addNewIncome(){
    Transaction transaction;

    system("cls");
    cout << "...Adding new income..." << endl;
    transaction = typeNewIncome();

    incomes.push_back(transaction);
}

Transaction TransactionManager::typeNewExpense(){
    Transaction transaction;
    string tempAmount;
    string tempDate;

    transaction.Id = 1;
    transaction.userId = LOGGED_IN_USER_ID;

    cout << "Enter the expense date. If you'd like current date press y" <<endl;
   tempDate = Utils::readLine();
    transaction.date = stoi(tempDate);

    cout << "Enter the expense name"<<endl;
    transaction.item = Utils::readLine();

    cout << "Enter the expense amount" << endl;
     tempAmount = Utils::readLine();
    transaction.amount = stod(tempAmount);

    return transaction;
}

Transaction TransactionManager::typeNewIncome(){

}
