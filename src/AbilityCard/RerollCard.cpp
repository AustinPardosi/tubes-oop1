// File: RerollCard.cpp
// Berisi implementasi dari kelas RerollCard

#include <iostream>
#include "RerollCard.hpp"
using namespace std;

// Konstruktor kartu re-roll
RerollCard::RerollCard() {
    this->commandID = 7;
    this->status = true;
}

// Getter dan setter
bool RerollCard::getCardStatus() const {
    return this->status;
}

// Member Function
// Menggunakan kartu yang dimiliki
void RerollCard::doCommand(Game& game) {
    
}