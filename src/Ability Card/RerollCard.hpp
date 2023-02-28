// RerollCard.hpp
#ifndef REROLL_CARD_HPP
#define REROLL_CARD_HPP

#include "AbilityCard.hpp"

class RerollCard : public AbilityCard {
    public:
        // Konstruktor kartu re-roll
        RerollCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void useCard();
};

#endif