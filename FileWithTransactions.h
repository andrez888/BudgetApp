#ifndef FILEWITHTRANSACTIONS_H
#define FILEWITHTRANSACTIONS_H

#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Markup.h"
#include "Markup.h"
#include "File.h"

using namespace std;
class FileWithTransactions : public File{
    int transactionLastId;

public:
    FileWithTransactions(string fileName) : File(fileName){
        transactionLastId = 0;
    }

    void addNewTransactionToFile(Transaction transaction);
    vector <Transaction> loadTransactionsFromFile(int loggedInUserId);
    int getTransactionLastId();
};
#endif
