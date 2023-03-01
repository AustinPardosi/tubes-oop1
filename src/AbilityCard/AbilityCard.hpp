// File: AbilityCard.hpp
// Berisi deklarasi dari kelas AbilityCard

#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include "../Command/Command.hpp"
#include "../Game/Game.hpp"

class AbilityCard : public Command {
    public:
        // Konstruktor kartu ability
        AbilityCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        virtual void doCommand(Game& game) = 0;

    protected:
        bool status; // berisi status dari penggunaan kartu ability
};

#endif