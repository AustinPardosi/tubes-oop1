#include "CommandInputException.hpp"
#include <iostream>

using namespace std;

CommandInputException::CommandInputException() {}

void CommandInputException::printMessage() {
    cout << "Please input a valid command" << endl;
}