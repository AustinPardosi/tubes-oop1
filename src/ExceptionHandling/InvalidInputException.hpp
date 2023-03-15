// File: InvalidInputException.hpp
// Berisi deklarasi dari kelas InvalidInputException

#ifndef INVALID_INPUT_EXCEPTION_HPP
#define INVALID_INPUT_EXCEPTION_HPP

#include "BaseException.hpp"

class InvalidInputException : public BaseException {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        InvalidInputException();

        /*--------------------------------------------------------------------*/
        /*-------------------------SHOW ERROR SEGMENT-------------------------*/

        // show an error when player tell an invalid input
        void printMessage();
};

#endif