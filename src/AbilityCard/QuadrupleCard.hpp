// File: QuadrupleCard.hpp
// Berisi deklarasi dari kelas QuadrupleCard

#ifndef QUADRUPLE_CARD_HPP
#define QUADRUPLE_CARD_HPP

#include "AbilityCard.hpp"

class QuadrupleCard : public AbilityCard {
    public:
        // Konstruktor kartu quadruple
        QuadrupleCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void doCommand(Game& game);
};

#endif