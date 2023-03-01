// File: RerollCard.hpp
// Berisi deklarasi dari kelas RerollCard

#ifndef REROLL_CARD_HPP
#define REROLL_CARD_HPP

#include "AbilityCard.hpp"

class Game;

class RerollCard : public AbilityCard {
    public:
        // Konstruktor kartu re-roll
        RerollCard();
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void doCommand(Game& game);
};

#endif