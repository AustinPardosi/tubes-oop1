#ifndef COMMAND_INPUT_EXCEPTION_HPP
#define COMMAND_INPUT_EXCEPTION_HPP

#include "BaseException.hpp"

class CommandInputException : public BaseException {
    public:
        CommandInputException();
        void printMessage();
};

#endif