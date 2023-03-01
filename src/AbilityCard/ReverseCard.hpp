// File: ReverseCard.hpp
// Berisi deklarasi dari kelas ReverseCard

#ifndef REVERSE_CARD_HPP
#define REVERSE_CARD_HPP

#include "AbilityCard.hpp"

class Game;

class ReverseCard : public AbilityCard {
    public:
        // Konstruktor kartu reverse
        ReverseCard();
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void doCommand(Game& game);
};

#endif