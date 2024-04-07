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
    getline(cin, input);
    return input;
}
