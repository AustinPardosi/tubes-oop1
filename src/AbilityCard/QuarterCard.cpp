// File: QuarterCard.cpp
// Berisi implementasi dari kelas QuarterCard

#include <iostream>
#include "QuarterCard.hpp"
using namespace std;

// Konstruktor kartu quarter
QuarterCard::QuarterCard() {
    this->commandID = 6;
    this->status = true;
}

// Getter dan setter
bool QuarterCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void QuarterCard::doCommand(Game& game) {
    game.setBonusPoint(game.getBonusPoint() / 4) ;
}