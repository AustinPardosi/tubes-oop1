// File: QuarterCard.cpp
// Berisi implementasi dari kelas QuarterCard

#include <iostream>
#include "QuarterCard.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor kartu quarter
QuarterCard::QuarterCard() {
    this->commandID = 6;
}

// Member Function
// Menggunakan kartu yang dimiliki
void QuarterCard::doCommand(Game& game) {
    game.doQuarter();
}