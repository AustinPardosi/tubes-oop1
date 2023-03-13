#include "AbilityCommandException.hpp"

AbilityCommandException::AbilityCommandException(bool _isUsed, string _command) {
    this->isUsed = _isUsed;
    this->command = _command;
}

void AbilityCommandException::printMessage() {
    if(this->isUsed) {
        cout << "\033[31m" << "Sorry, you already used the " << this->command << " ability card" << endl;
        cout << "Please input another command!" << "\033[0m" << endl;
    } else {
        cout << "\033[31m" << "Oops... someone has turned off your ability card :(" << endl; 
        cout << "Please input another command!" << "\033[0m" << endl;
    }
}