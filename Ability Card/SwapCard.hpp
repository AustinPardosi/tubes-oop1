// SwapCard.hpp
#ifndef SWAP_CARD_HPP
#define SWAP_CARD_HPP

#include "AbilityCard.hpp"

class SwapCard : public AbilityCard {
    public:
        // Konstruktor kartu swap
        SwapCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void useCard();
};

#endif