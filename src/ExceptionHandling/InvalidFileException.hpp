// File: InvalidFileException.hpp
// Berisi deklarasi dari kelas InvalidFileException

#ifndef INVALID_FILE_EXCEPTION_HPP
#define INVALID_FILE_EXCEPTION_HPP

#include "BaseException.hpp"

class InvalidFileException : public BaseException {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        InvalidFileException();

        /*--------------------------------------------------------------------*/
        /*-------------------------SHOW ERROR SEGMENT-------------------------*/

        // show an error when file is not found
        void printMessage();
};

#endif