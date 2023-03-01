// File: SwapCard.cpp
// Berisi implementasi dari kelas SwapCard

#include <iostream>
#include "SwapCard.hpp"
using namespace std;

// Konstruktor kartu swap
SwapCard::SwapCard() {
    this->commandID = 8;
    this->status = true;
}

// Getter dan setter
bool SwapCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void SwapCard::doCommand(Game& game) {
    
}