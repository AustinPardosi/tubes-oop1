// File: QuarterCard.hpp
// Berisi deklarasi dari kelas QuarterCard

#ifndef QUARTER_CARD_HPP
#define QUARTER_CARD_HPP

#include "AbilityCard.hpp"

class QuarterCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        QuarterCard();       
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do quarter ability
        void doCommand(Game& game);
};

#endif