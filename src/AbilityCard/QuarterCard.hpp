// File: QuarterCard.hpp
// Berisi deklarasi dari kelas QuarterCard

#ifndef QUARTER_CARD_HPP
#define QUARTER_CARD_HPP

#include "AbilityCard.hpp"

class Game;

class QuarterCard : public AbilityCard {
    public:
        // Konstruktor kartu quarter
        QuarterCard();       
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void doCommand(Game& game);
};

#endif