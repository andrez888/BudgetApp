#include "FileWithTransactions.h"

void FileWithTransactions::addNewTransactionToFile(Transaction transaction){
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
    xml.AddElem("TransactionId", 1);
    xml.AddElem("UserId", transaction.userId);
    xml.AddElem("Date", transaction.date);
    xml.AddElem("Item", transaction.item);
    xml.AddElem("Amount", transaction.amount);
    xml.OutOfElem(); // Move out of <User>

    xml.Save(FILE_NAME);

}
