
#include <iostream>
#include <vector>
#include "Transaction.h"
#include "Markup.h"

using namespace std;
class FileWithTransactions{
    const string FILE_NAME;
    int transactionLastId;

public:
    FileWithTransactions(string fileName) : FILE_NAME(fileName){
        transactionLastId = 0;
    }

    void addNewTransactionToFile(Transaction transaction);
    vector <Transaction> loadTransactionsFromFile(int loggedInUserId);
    int getTransactionLastId();


};
