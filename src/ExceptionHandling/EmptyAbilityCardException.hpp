// File: EmptyAbilityCardException.hpp
// Berisi deklarasi dari kelas EmptyAbilityCardException

#ifndef EMPTY_ABILITY_CARD_EXCEPTION_HPP
#define EMPTY_ABILITY_CARD_EXCEPTION_HPP

#include "BaseException.hpp"

class EmptyAbilityCardException : public BaseException {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        EmptyAbilityCardException();

        /*--------------------------------------------------------------------*/
        /*-------------------------SHOW ERROR SEGMENT-------------------------*/

        // show an error when player try to use ability that they do not have
        void printMessage();
};

#endif