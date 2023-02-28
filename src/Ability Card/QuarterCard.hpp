// File: QuarterCard.hpp
// Berisi deklarasi dari kelas QuarterCard

#ifndef QUARTER_CARD_HPP
#define QUARTER_CARD_HPP

#include "AbilityCard.hpp"

class QuarterCard : public AbilityCard {
    public:
        // Konstruktor kartu quarter
        QuarterCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void useCard(const Game& game);
};

#endif