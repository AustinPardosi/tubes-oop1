#ifndef BASE_EXCEPTION_HPP
#define BASE_EXCEPTION_HPP

#include <iostream>
using namespace std;

class BaseException{
    public:
        virtual void printMessage() = 0;
};

#endif