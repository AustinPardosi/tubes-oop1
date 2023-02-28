// AbilityCard.hpp
#ifndef ABILITY_CARD_HPP
#define ABILITY_CARD_HPP

#include "Command.hpp"

class AbilityCard : public Command {
    public:
        // Konstruktor kartu ability
        AbilityCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        virtual void useCard();

    protected:
        bool status; // berisi status dari penggunaan kartu ability
};

#endif