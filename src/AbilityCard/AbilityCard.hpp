// File: AbilityCard.hpp
// Berisi deklarasi dari kelas AbilityCard

#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include "../Command/Command.hpp"

class AbilityCard : public Command {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        AbilityCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // abstract method to execute ability, still too abstract on this class
        virtual void doCommand(Game& game) = 0;
};

#endif