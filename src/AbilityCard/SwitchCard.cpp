// File: SwitchCard.cpp
// Berisi implementasi dari kelas SwitchCard

#include <iostream>
#include "SwitchCard.hpp"
using namespace std;

// Konstruktor kartu switch
SwitchCard::SwitchCard() {
    this->commandID = 8;
    this->status = true;
}

// Getter dan setter
bool SwitchCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void SwitchCard::doCommand(Game& game) {
    
}