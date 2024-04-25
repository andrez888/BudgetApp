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

    transaction.id = expensesFile.getTransactionLastId() + 1;
    transaction.userId = LOGGED_IN_USER_ID;

    do {
        cout << "Enter the expense date in format yyyy-mm-dd. If you'd like current date press y" <<endl;
        date = Utils::readLine();
    } while( !DateManager::validateDate(date));
    transaction.date = DateManager::convertStringDateToInt(date);

    cout << "Enter the name of the expense"<<endl;
    transaction.item = Utils::readLine();

    do {
        cout << "Enter the expense amount" << endl;
        tempAmount = Utils::readLine();
    } while(!Utils::validateAmount(tempAmount));
    transaction.amount = stod(tempAmount);

    cout << "New expense has been added successfully" << endl;
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

    cout << "Enter the name of the income"<<endl;
    transaction.item = Utils::readLine();

   do {
        cout << "Enter the income amount" << endl;
        tempAmount = Utils::readLine();
    } while(!Utils::validateAmount(tempAmount));
    transaction.amount = stod(tempAmount);

    cout << "New income has been added successfully" << endl;
    system("pause");

    return transaction;
}

void TransactionManager::showBalance(int startDate, int endDate) {
    system("cls");

    int expensesCounter = 0;
    int incomesCounter = 0;
    double expensesSum = 0;
    double incomesSum = 0;

    sort(incomes.begin(), incomes.end());
    sort(expenses.begin(), expenses.end());

    cout << "Your transactions: " << endl << endl;
    cout << "Incomes:" << endl;

    for(const Transaction& transaction : incomes) {
        if (transaction.date >= startDate && transaction.date <= endDate) {
            incomesCounter++;
            cout <<  incomesCounter << left << setw(10) << ". Income: ";
            cout << left << setw(15) << transaction.item << " Date: ";
            cout << left << setw(12) << DateManager::convertIntDateToStringWithDashes(transaction.date);
            cout << " Amount: " << fixed << setprecision(2) << transaction.amount << endl;
        }
    }

    if(incomesCounter == 0) {
        cout << "No income transactions were recorded for the selected period." << endl;
    }
    incomesSum = calculateBalance(startDate, endDate, incomes);
    cout << "Total income: " << fixed << setprecision(2) << incomesSum << endl;

    cout << endl << "Expenses:" << endl;

    for(const Transaction& transaction : expenses) {
        if (transaction.date >= startDate && transaction.date <= endDate) {
            expensesCounter++;
            cout <<  expensesCounter << left << setw(10) << ". Expense: ";
            cout << left << setw(15) << transaction.item << "Date: ";
            cout << left << setw(12) << DateManager::convertIntDateToStringWithDashes(transaction.date);
            cout << " Amount: " << fixed << setprecision(2) << transaction.amount << endl;
        }
    }

    if(expensesCounter == 0) {
        cout << "No expense transactions were recorded for the selected period." << endl;
    }
    expensesSum = calculateBalance(startDate, endDate, expenses);
    cout << "Total expense: " << fixed << setprecision(2) << expensesSum << endl;

    double sumTransactions = incomesSum - expensesSum;
    cout << endl << "Total balance (income - expense): " << fixed << setprecision(2) << sumTransactions << endl;
    system("pause");
}

void TransactionManager::showCurrentMonthBalance() {
    showBalance(DateManager::getCurrentMonthFirstDayDate(), DateManager::getCurrentDate());
}

void TransactionManager::showPreviousMonthBalance() {
    showBalance(DateManager::getPreviousMonthFirstDayDate(), DateManager::getPreviousMonthLastDayDate());
}

void TransactionManager::showSelectedPeriodBalance() {

    system("cls");
    string dateStart;
    string dateEnd;
    int dateStartInt, dateEndInt;

    do {
        cout << "Enter the date in format yyyy-mm-dd from which you'd like to start" << endl;
        dateStart = Utils::readLine();
    } while(!DateManager::validateDate(dateStart));
    dateStartInt = DateManager::convertStringDateToInt(dateStart);

    do {
        cout << "Enter the date in format yyyy-mm-dd which you'd like to end with" << endl;
        dateEnd = Utils::readLine();
    } while(!DateManager::validateDate(dateEnd));
    dateEndInt = DateManager::convertStringDateToInt(dateEnd);

    showBalance(dateStartInt, dateEndInt);
}

double TransactionManager::calculateBalance(int startDate, int endDate, vector<Transaction> &transactions) {
    double balanceSum = 0;

    for(Transaction transaction : transactions) {
        if(transaction.date >= startDate && transaction.date <= endDate) {
            balanceSum += transaction.amount;
        }
    }
    return balanceSum;
}


