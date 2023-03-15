// File: AbilitylessCard.hpp
// Berisi deklarasi dari kelas AbilitylessCard

#ifndef ABILITYLESS_CARD_HPP
#define ABILITYLESS_CARD_HPP

#include "AbilityCard.hpp"

class AbilitylessCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor 
        AbilitylessCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do the abilityless ability
        void doCommand(Game& game);
};

#endif