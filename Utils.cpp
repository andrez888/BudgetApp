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
