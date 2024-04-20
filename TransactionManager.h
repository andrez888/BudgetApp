#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"
#include "FileWithTransactions.h"
#include "Utils.h"
#include "DateManager.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class TransactionManager {

    const int LOGGED_IN_USER_ID;
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    FileWithTransactions expensesFile;
    FileWithTransactions incomesFile;

    Transaction typeNewExpense() ;
    Transaction typeNewIncome();
    void showBalance(int startDate, int endDate);


public:
    TransactionManager(int loggedInUserId, string expensesFileName, string incomesFileName) :
        LOGGED_IN_USER_ID(loggedInUserId), expensesFile( expensesFileName), incomesFile(incomesFileName) {
            expenses = expensesFile.loadTransactionsFromFile(LOGGED_IN_USER_ID);
            incomes = incomesFile.loadTransactionsFromFile(LOGGED_IN_USER_ID);
    }
    void addNewExpense();
    void addNewIncome();

    void showCurrentMonthBalance();
    void showPreviousMonthBalance();
    void showSelectedPeriodBalance();
    static bool compareByDate(const Transaction& t1, const Transaction& t2);

};

#endif
