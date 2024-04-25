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

      bool operator<(const Transaction& other) const {
        return date < other.date;
    }
};
#endif
