// File: ReverseCard.cpp
// Berisi implementasi dari kelas ReverseCard

#include <iostream>
#include "ReverseCard.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor kartu reverse
ReverseCard::ReverseCard() {
    this->commandID = 8;
}

// Member Function
// Menggunakan kartu yang dimiliki
void ReverseCard::doCommand(Game& game) {
    game.doReverse();
}