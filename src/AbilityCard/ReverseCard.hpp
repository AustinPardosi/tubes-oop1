// File: ReverseCard.hpp
// Berisi deklarasi dari kelas ReverseCard

#ifndef REVERSE_CARD_HPP
#define REVERSE_CARD_HPP

#include "AbilityCard.hpp"

class ReverseCard : public AbilityCard {
    public:
        // Konstruktor kartu reverse
        ReverseCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void useCard(const Game& game);
};

#endif