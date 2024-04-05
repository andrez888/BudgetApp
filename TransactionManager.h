#ifndef TRANSACTIONMANAGER_H
#define TRANSACTIONMANAGER_H

#include "Transaction.h"

using namespace std;
class TransactionManager {
    const int LOGGED_IN_USER_ID;
    //fileWithTransactions : FileWithTransactions
    vector <Transaction> incomes;
    vector <Transaction> expenses;

    Transaction typeNewExpense() ;
    Transaction typeNewIncome();
public:
    void addNewExpesne();
    void addNewIncome();

    void ShowBalanceSheetofCurrentMonth();
    void ShowBalanceSheetofPreviousMonth();
    void ShowSheetofSelectedPeriod();

};

#endif
