#include "InvalidInputException.hpp"

InvalidInputException::InvalidInputException() {}

void InvalidInputException::printMessage() {
    cout << "Please input a valid command!" << endl;
}