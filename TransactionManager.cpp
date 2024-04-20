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
    string date;

    transaction.id = expensesFile.getTransactionLastId();
    transaction.userId = LOGGED_IN_USER_ID;

    do {
        cout << "Enter the income date in format yyyy-mm-dd. If you'd like current date press y" <<endl;
        date = Utils::readLine();
    } while( !DateManager::validateDate(date));
    transaction.date = DateManager::convertStringDateToInt(date);

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
    string date;

    transaction.id = incomesFile.getTransactionLastId() +1;
    transaction.userId = LOGGED_IN_USER_ID;

    do {
        cout << "Enter the income date in format yyyy-mm-dd. If you'd like current date press y" <<endl;
        date = Utils::readLine();
    } while( !DateManager::validateDate(date) );
    transaction.date = DateManager::convertStringDateToInt(date);

    cout << "Enter the income name"<<endl;
    transaction.item = Utils::readLine();

    cout << "Enter the icome amount" << endl;
    tempAmount = Utils::readLine();
    transaction.amount = stod(tempAmount);

    cout << "New income has been added" << endl;
    system("pause");

    return transaction;
}

void TransactionManager::showBalance(int startDate, int endDate){

    int expensesCounter = 0;
    int incomesCounter = 0;
    sort(incomes.begin(), incomes.end(), &TransactionManager::compareByDate);
    sort(expenses.begin(), expenses.end(), &TransactionManager::compareByDate);
    system("cls");

    cout << "Your transactions: " << endl << endl;
    cout << "Incomes:" << endl;

    for(Transaction transaction : incomes){
        if( transaction.date >= startDate && transaction.date <= endDate){
                incomesCounter++;
            cout << incomesCounter << ".Income: " << transaction.item << " Date: " << DateManager::convertIntDateToStringWithDashes(transaction.date) <<
            " Amount: " << transaction.amount << endl;
        }
    }

    if(incomesCounter == 0){
        cout << "There are not incomes in selected period" << endl;
    }

    cout << endl << "Expenses:" << endl;

    for(Transaction transaction : expenses){
        if( transaction.date >= startDate && transaction.date <= endDate){
                expensesCounter++;
            cout << expensesCounter << ".Expense: " << transaction.item << " Date: " << DateManager::convertIntDateToStringWithDashes(transaction.date) <<
            " Amount: " << transaction.amount << endl;
        }
    }

    if(expensesCounter == 0){
        cout << "There are not expenses in selected period" << endl;
    }
    system("pause");
}

void TransactionManager::showCurrentMonthBalance(){
    showBalance(DateManager::getCurrentMonthFirstDayDate(), DateManager::getCurrentDate());
}

void TransactionManager::showPreviousMonthBalance(){
    showBalance(DateManager::getPreviousMonthFirstDayDate(), DateManager::getPreviousMonthLastDayDate());
}

void TransactionManager::showSelectedPeriodBalance(){

    system("cls");
    string dateStart;
    string dateEnd;
    int dateStartInt, dateEndInt;

    do{
    cout << "Enter the date in format yyyy-mm-dd which from you'd like to start" << endl;
    dateStart = Utils::readLine();
    }while(!DateManager::validateDate(dateStart));
    dateStartInt = DateManager::convertStringDateToInt(dateStart);

    do{
    cout << "Enter the date in format yyyy-mm-dd which from you'd like to end" << endl;
    dateEnd = Utils::readLine();
    }while(!DateManager::validateDate(dateEnd));
    dateEndInt = DateManager::convertStringDateToInt(dateEnd);

    showBalance(dateStartInt, dateEndInt);
}

bool TransactionManager::compareByDate(const Transaction& t1, const Transaction& t2) {
    return t1.date < t2.date;
}

