#include "AbilityCommandException.hpp"
#include <iostream>

using namespace std;

AbilityCommandException::AbilityCommandException(bool _isUsed, string _command) {
    this->isUsed = _isUsed;
    this->command = _command;
}

void AbilityCommandException::printMessage() {
    if(this->isUsed) {
        cout << "Sorry, you already used the " << this->command + " ability card. Please input another command" << endl;
    } else {
        cout << "Sorry, your " + this->command + " ability card has been rendered useless. Please input another command" << endl;
    }
}