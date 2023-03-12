#ifndef NAME_INPUT_EXCEPTION_HPP
#define NAME_INPUT_EXCEPTION_HPP

#include "BaseException.hpp"

class NameInputException : public BaseException {
    public:
        NameInputException();
        void printMessage();
};

#endif