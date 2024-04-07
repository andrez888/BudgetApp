#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"
#include "Utils.h"
#include <vector>

using namespace std;
class TransactionManager {
    const int LOGGED_IN_USER_ID;
    //fileWithTransactions : FileWithTransactions
    vector <Transaction> incomes;
    vector <Transaction> expenses;

    Transaction typeNewExpense() ;
    Transaction typeNewIncome();
public:
    TransactionManager(int loggedInUserId) :
        LOGGED_IN_USER_ID(loggedInUserId){
    }
    void addNewExpense();
    void addNewIncome();

    void ShowBalanceSheetofCurrentMonth();
    void ShowBalanceSheetofPreviousMonth();
    void ShowSheetofSelectedPeriod();

};

#endif
