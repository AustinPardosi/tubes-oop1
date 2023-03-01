// File: RerollCard.cpp
// Berisi implementasi dari kelas RerollCard

#include <iostream>
#include "RerollCard.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor kartu re-roll
RerollCard::RerollCard() {
    this->commandID = 7;
}

// Member Function
// Menggunakan kartu yang dimiliki
void RerollCard::doCommand(Game& game) {
    
}