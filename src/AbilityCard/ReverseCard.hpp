// File: ReverseCard.hpp
// Berisi deklarasi dari kelas ReverseCard

#ifndef REVERSE_CARD_HPP
#define REVERSE_CARD_HPP

#include "AbilityCard.hpp"

class ReverseCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        ReverseCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // tell the game object to do reverse ability
        void doCommand(Game& game);
};

#endif