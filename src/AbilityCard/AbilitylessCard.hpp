// File: AbilitylessCard.hpp
// Berisi deklarasi dari kelas AbilitylessCard

#ifndef ABILITYLESS_CARD_HPP
#define ABILITYLESS_CARD_HPP

#include "AbilityCard.hpp"

class AbilitylessCard : public AbilityCard {
    public:
        // Konstruktor kartu abilityless
        AbilitylessCard();
        
        // Getter dan setter
        bool getCardStatus() const;
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        void useCard(const Game& game);
};

#endif