// File: AbilitylessCard.cpp
// Berisi implementasi dari kelas AbilitylessCard

#include <iostream>
#include "AbilitylessCard.hpp"
using namespace std;

// Konstruktor kartu abilityless
AbilitylessCard::AbilitylessCard() {
    this->commandID = 4;
    this->status = true;
}

// Getter dan setter
bool AbilitylessCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void AbilitylessCard::doCommand(Game& game) {
    
}