#include "AbilityCommandException.hpp"

AbilityCommandException::AbilityCommandException(bool _isUsed, string _command) {
    this->isUsed = _isUsed;
    this->command = _command;
}

void AbilityCommandException::printMessage() {
    if(this->isUsed) {
        cout << "Sorry, you already used the " << this->command << " ability card" << endl;
        cout << "Please input another command!" << endl;
    } else {
        cout << "Oops... someone has turned off your ability card :(" << endl; 
        cout << "Please input another command!" << endl;
    }
}