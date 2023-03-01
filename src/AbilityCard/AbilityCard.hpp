// File: AbilityCard.hpp
// Berisi deklarasi dari kelas AbilityCard

#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include "../Command/Command.hpp"

class Game;

class AbilityCard : public Command {
    public:
        // Konstruktor kartu ability
        AbilityCard();
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        virtual void doCommand(Game& game) = 0;
};

#endif