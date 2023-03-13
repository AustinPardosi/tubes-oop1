#include "InvalidInputException.hpp"

InvalidInputException::InvalidInputException() {}

void InvalidInputException::printMessage() {
    cout << "\033[31m" << "Please input a valid command!" << "\033[0m" << endl;
}