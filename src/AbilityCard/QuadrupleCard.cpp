// File: QuadrupleCard.cpp
// Berisi implementasi dari kelas QuadrupleCard

#include <iostream>
#include "QuadrupleCard.hpp"
using namespace std;

// Konstruktor kartu quadruple
QuadrupleCard::QuadrupleCard() {
    this->commandID = 5;
    this->status = true;
}

// Getter dan setter
bool QuadrupleCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void QuadrupleCard::doCommand(Game& game) {
    game.setBonusPoint(game.getBonusPoint() * 4) ;
}