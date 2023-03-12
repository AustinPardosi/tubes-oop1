#include "EmptyAbilityCardException.hpp"
#include <iostream>

using namespace std;

EmptyAbilityCardException::EmptyAbilityCardException() {}

void EmptyAbilityCardException::printMessage() {
    cout << "Looks like you do not have the ability card..." << endl;
    cout << "Please input another command" << endl;
}