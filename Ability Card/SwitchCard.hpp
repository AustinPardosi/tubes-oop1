// SwitchCard.hpp
#ifndef SWITCH_CARD_HPP
#define SWITCH_CARD_HPP

#include "AbilityCard.hpp"

class SwitchCard : public AbilityCard {
    public:
        // Konstruktor kartu switch
        SwitchCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void useCard();
};

#endif