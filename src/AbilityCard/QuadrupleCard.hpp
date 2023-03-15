// File: QuadrupleCard.hpp
// Berisi deklarasi dari kelas QuadrupleCard

#ifndef QUADRUPLE_CARD_HPP
#define QUADRUPLE_CARD_HPP

#include "AbilityCard.hpp"

class QuadrupleCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        QuadrupleCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do quadruple ability
        void doCommand(Game& game);
};

#endif