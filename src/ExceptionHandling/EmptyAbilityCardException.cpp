#include "EmptyAbilityCardException.hpp"

EmptyAbilityCardException::EmptyAbilityCardException() {}

void EmptyAbilityCardException::printMessage() {
    cout << "\033[31m" << "Looks like you do not have the ability card..." << endl;
    cout << "Please input another command" << "\033[0m" << endl;
}