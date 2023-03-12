#ifndef EMPTY_ABILITY_CARD_EXCEPTION_HPP
#define EMPTY_ABILITY_CARD_EXCEPTION_HPP

#include "BaseException.hpp"

class EmptyAbilityCardException : public BaseException {
    public:
        EmptyAbilityCardException();
        void printMessage();
};

#endif