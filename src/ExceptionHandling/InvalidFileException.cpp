// File: InvalidFileException.cpp
// Berisi implementasi dari kelas InvalidFileException

#include "InvalidFileException.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

InvalidFileException::InvalidFileException() {}

/*--------------------------------------------------------------------*/
/*-------------------------SHOW ERROR SEGMENT-------------------------*/
    
void InvalidFileException::printMessage() {
    cout << "\033[31m" << "File txt cannot be opened" << endl;
    cout << "Please check your txt file" << "\033[0m" << endl;
}