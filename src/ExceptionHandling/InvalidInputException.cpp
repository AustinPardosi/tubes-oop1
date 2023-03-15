// File: InvalidInputException.cpp
// Berisi implementasi dari kelas InvalidInputException

#include "InvalidInputException.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

InvalidInputException::InvalidInputException() {}

/*--------------------------------------------------------------------*/
/*-------------------------SHOW ERROR SEGMENT-------------------------*/

void InvalidInputException::printMessage() {
    cout << "\033[31m" << "Please input a valid command!" << "\033[0m" << endl;
}