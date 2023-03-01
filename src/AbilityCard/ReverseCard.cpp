// File: ReverseCard.cpp
// Berisi implementasi dari kelas ReverseCard

#include <iostream>
#include "ReverseCard.hpp"
using namespace std;

// Konstruktor kartu reverse
ReverseCard::ReverseCard() {
    this->commandID = 8;
    this->status = true;
}

// Getter dan setter
bool ReverseCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void ReverseCard::doCommand(Game& game) {
    
}