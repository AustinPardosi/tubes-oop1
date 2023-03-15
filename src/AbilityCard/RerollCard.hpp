// File: RerollCard.hpp
// Berisi deklarasi dari kelas RerollCard

#ifndef REROLL_CARD_HPP
#define REROLL_CARD_HPP

#include "AbilityCard.hpp"

class RerollCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        RerollCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do reroll ability
        void doCommand(Game& game);
};

#endif