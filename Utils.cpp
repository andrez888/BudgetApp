#include "Utils.h"


char Utils::getCharacter() {
    string input = "";
    char sign  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            sign = input[0];
            break;
        }
        cout << "It's not single character. Try again" << endl;
    }
    return sign;
}

string Utils::readLine() {
    string input = "";
    do {
        getline(cin, input);
        if(input.empty()) {
            cout << "You typed blank. Please enter something" << endl;
        }

    } while(input.empty());

        return input;
}

bool Utils::validateAmount( string &amount) {

    for (char& c : amount) {
        if (c == ',') {
            c = '.';
        }
    }

    if(amount[0] == '0') {
        if(amount[1] != '.') {
            cout << "Incorrect amount value" << endl;
            return false;
        }
    }

    stringstream ss(amount);
    double value;
    if (ss >> value) {
        char remaining;
        if (!(ss >> remaining) && value > 0 ) {
            return true;
        }
    }
    cout << "Incorrect amount value" << endl;
    return false;
}


