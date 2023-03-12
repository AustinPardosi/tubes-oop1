#include "InvalidInputException.hpp"
#include <iostream>

using namespace std;

InvalidInputException::InvalidInputException() {}

void InvalidInputException::printMessage() {
    cout << "Please input a valid command!" << endl;
}