#include "NameInputException.hpp"
#include <iostream>

using namespace std;

NameInputException::NameInputException() {}

void NameInputException::printMessage() {
    cout << "Please input a valid name" << endl;
}