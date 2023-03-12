// File: QuadrupleCard.cpp
// Berisi implementasi dari kelas QuadrupleCard

#include <iostream>
#include "QuadrupleCard.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor kartu quadruple
QuadrupleCard::QuadrupleCard() {
    this->commandID = 5;
}

// Member Function
// Menggunakan kartu yang dimiliki
void QuadrupleCard::doCommand(Game& game) {
    game.doQuadruple();
}