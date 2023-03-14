#ifndef INVALID_FILE_EXCEPTION_HPP
#define INVALID_FILE_EXCEPTION_HPP

#include "BaseException.hpp"

class InvalidFileException : public BaseException {
    public:
        InvalidFileException();
        void printMessage();
};

#endif