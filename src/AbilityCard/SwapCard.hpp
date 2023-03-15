// File: SwapCard.hpp
// Berisi deklarasi dari kelas SwapCard

#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include "AbilityCard.hpp"

class SwapCard : public AbilityCard {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        SwapCard();
        
        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/
        
        // tell the game object to do swap ability
        void doCommand(Game& game);
};

#endif