
#include <iostream>
#include "Transaction.h"
#include "Markup.h"

using namespace std;
class FileWithTransactions{
    const string FILE_NAME;

public:
    FileWithTransactions(string fileName) : FILE_NAME(fileName){
    }

    void addNewTransactionToFile(Transaction transaction);


};
