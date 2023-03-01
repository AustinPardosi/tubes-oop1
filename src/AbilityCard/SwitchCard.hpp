// File: SwitchCard.hpp
// Berisi deklarasi dari kelas SwitchCard

#ifndef SWITCH_CARD_HPP
#define SWITCH_CARD_HPP

#include "AbilityCard.hpp"

class Game;

class SwitchCard : public AbilityCard {
    public:
        // Konstruktor kartu switch
        SwitchCard();
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void doCommand(Game& game);
};

#endif