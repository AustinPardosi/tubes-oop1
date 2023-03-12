#ifndef INVALID_INPUT_EXCEPTION_HPP
#define INVALID_INPUT_EXCEPTION_HPP

#include "BaseException.hpp"

class InvalidInputException : public BaseException {
    public:
        InvalidInputException();
        void printMessage();
};

#endif