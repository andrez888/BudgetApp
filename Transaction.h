#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

using namespace std;

struct Transaction {
    int id;
    int userId;
    int date;
    string item;
    double amount;
};

#endif
