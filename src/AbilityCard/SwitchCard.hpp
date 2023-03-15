// File: SwitchCard.hpp
// Berisi deklarasi dari kelas SwitchCard

#ifndef SWITCH_CARD_HPP
#define SWITCH_CARD_HPP

#include "AbilityCard.hpp"

class SwitchCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        SwitchCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do switch ability
        void doCommand(Game& game);
};

#endif