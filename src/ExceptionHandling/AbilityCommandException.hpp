#ifndef ABILITY_COMMAND_EXCEPTION_HPP
#define ABILITY_COMMAND_EXCEPTION_HPP

#include "BaseException.hpp"

class AbilityCommandException : public BaseException {
    public:
        AbilityCommandException(bool _isUsed, string _command);
        void printMessage();
    private:
        bool isUsed;
        string command;
};

#endif