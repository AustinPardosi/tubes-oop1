// File: AbilityCommandException.hpp
// Berisi deklarasi dari kelas AbilityCommandException

#ifndef ABILITY_COMMAND_EXCEPTION_HPP
#define ABILITY_COMMAND_EXCEPTION_HPP

#include "BaseException.hpp"

class AbilityCommandException : public BaseException {
    private:
        bool isUsed;
        string command;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        AbilityCommandException(bool _isUsed, string _command);
        
        /*--------------------------------------------------------------------*/
        /*-------------------------SHOW ERROR SEGMENT-------------------------*/

        // show an error when player try to use their ability card
        void printMessage();
};

#endif