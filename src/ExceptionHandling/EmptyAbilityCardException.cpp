#include "EmptyAbilityCardException.hpp"
#include <iostream>

using namespace std;

EmptyAbilityCardException::EmptyAbilityCardException() {}

void EmptyAbilityCardException::printMessage() {
    cout << "Sorry, you do not have the ability card. Please input another command" << endl;
}