// File: BaseException.hpp
// Berisi deklarasi dari kelas abstrak BaseException

#ifndef BASE_EXCEPTION_HPP
#define BASE_EXCEPTION_HPP

#include <iostream>
using namespace std;

class BaseException{
    public:
        /*--------------------------------------------------------------------*/
        /*-------------------------SHOW ERROR SEGMENT-------------------------*/
        
        // show the error that happen during program runtime
        virtual void printMessage() = 0;
};

#endif