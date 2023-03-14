#include "InvalidFileException.hpp"

InvalidFileException::InvalidFileException() {}

void InvalidFileException::printMessage() {
    cout << "\033[31m" << "File txt cannot be opened" << endl;
    cout << "Please check your txt file" << "\033[0m" << endl;
}