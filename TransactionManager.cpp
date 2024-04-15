#include "TransactionManager.h"

void TransactionManager::addNewExpense() {
    Transaction transaction;

    system("cls");
    cout << "...Adding new expense..." << endl;
    transaction = typeNewExpense();

    expenses.push_back(transaction);
    expensesFile.addNewTransactionToFile(transaction);
}

void TransactionManager::addNewIncome() {
    Transaction transaction;

    system("cls");
    cout << "...Adding new income..." << endl;
    transaction = typeNewIncome();

    incomes.push_back(transaction);
    incomesFile.addNewTransactionToFile(transaction);
}

Transaction TransactionManager::typeNewExpense() {
    Transaction transaction;
    string tempAmount;
    string tempDate;

     transaction.id = expensesFile.getTransactionLastId();
    transaction.userId = LOGGED_IN_USER_ID;

    cout << "Enter the expense date. If you'd like current date press y" <<endl;
    tempDate = Utils::readLine();
    transaction.date = stoi(tempDate);

    cout << "Enter the expense name"<<endl;
    transaction.item = Utils::readLine();

    cout << "Enter the expense amount" << endl;
    tempAmount = Utils::readLine();
    transaction.amount = stod(tempAmount);

    cout << "New expense has been added" << endl;
    system("pause");

    return transaction;
}

Transaction TransactionManager::typeNewIncome() {
    Transaction transaction;
    string tempAmount;
    string tempDate;

    transaction.id = incomesFile.getTransactionLastId();
    transaction.userId = LOGGED_IN_USER_ID;
    do{
    cout << "Enter the income date in format yyyy-mm-dd. If you'd like current date press y" <<endl;
    tempDate = Utils::readLine();
    }while( !DateManager::validateDate(tempDate) );
    transaction.date=5;

    cout << "Enter the income name"<<endl;
    transaction.item = Utils::readLine();

    cout << "Enter the icome amount" << endl;
    tempAmount = Utils::readLine();
    transaction.amount = stod(tempAmount);

    cout << "New income has been added" << endl;
    system("pause");

    return transaction;
}
