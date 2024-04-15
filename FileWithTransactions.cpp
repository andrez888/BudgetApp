#include "FileWithTransactions.h"

void FileWithTransactions::addNewTransactionToFile(Transaction transaction) {
    CMarkup xml;

    bool fileExists = xml.Load(FILE_NAME);

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.15\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Transactions");

    } else {
        xml.FindElem(); // Move to the root element
    }

    xml.IntoElem();
    xml.AddElem("Transaction");
    xml.IntoElem();
    xml.AddElem("TransactionId", transaction.id);
    transactionLastId++;
    xml.AddElem("UserId", transaction.userId);
    xml.AddElem("Date", transaction.date);
    xml.AddElem("Item", transaction.item);
    xml.AddElem("Amount", transaction.amount);
    xml.OutOfElem(); // Move out of <User>

    xml.Save(FILE_NAME);

}

vector <Transaction>  FileWithTransactions::loadTransactionsFromFile(int loggedInUserId){

    vector<Transaction> transactions;

    CMarkup xml;
    if (!xml.Load(FILE_NAME)) {
        cerr << "Failed to load transactions from file." << endl;
        return transactions;
    }

    if (!xml.FindElem("Transactions")) {
        cerr << "Error: Root node 'Transactions' not found in the XML file." << endl;
        return transactions;
    }

    xml.IntoElem();
    while (xml.FindElem("Transaction")) {
        Transaction transaction;
        xml.IntoElem();
        xml.FindElem("TransactionId");
        transaction.id = stoi(xml.GetData());
        transactionLastId = transaction.id;
        xml.FindElem("UserId");
        int loadedUserId = stoi(xml.GetData());
        if (loadedUserId != loggedInUserId) { // Check against the provided loggedInUserId
            // Skip transactions not belonging to the logged-in user
            xml.OutOfElem(); // Move out of <Transaction>
            continue;
        }
        transaction.userId = loadedUserId;
        xml.FindElem("Date");
        transaction.date = stoi(xml.GetData());
        xml.FindElem("Item");
        transaction.item = xml.GetData();
        xml.FindElem("Amount");
        transaction.amount = stod(xml.GetData());
        xml.OutOfElem(); // Move out of <Transaction>
        transactions.push_back(transaction);
    }



    return transactions;
}

int FileWithTransactions::getTransactionLastId(){
    return transactionLastId;
}
