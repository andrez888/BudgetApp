#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"
#include "FileWithTransactions.h"
#include "Utils.h"
#include <vector>

using namespace std;
class TransactionManager {
    const int LOGGED_IN_USER_ID;
    //fileWithTransactions : FileWithTransactions
    vector <Transaction> incomes;
    vector <Transaction> expenses;
    FileWithTransactions expensesFile;
    FileWithTransactions incomesFile;

    Transaction typeNewExpense() ;
    Transaction typeNewIncome();
public:
    TransactionManager(int loggedInUserId, string expensesFileName, string incomesFileName) :
        LOGGED_IN_USER_ID(loggedInUserId), expensesFile( expensesFileName), incomesFile(incomesFileName){
    }
    void addNewExpense();
    void addNewIncome();

    void ShowBalanceSheetofCurrentMonth();
    void ShowBalanceSheetofPreviousMonth();
    void ShowSheetofSelectedPeriod();

};

#endif
