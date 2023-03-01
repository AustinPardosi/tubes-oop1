// File: AbilityCard.cpp
// Berisi implementasi dari kelas AbilityCard

#include <iostream>
#include "AbilityCard.hpp"
using namespace std;

// Konstruktor kartu ability
AbilityCard::AbilityCard() {
    this->commandID = 4;
    this->status = true;
}

// Getter dan setter
bool AbilityCard::getCardStatus() const {
    return this->status;
}