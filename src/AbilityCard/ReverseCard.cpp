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
    int turnIdx = game.getIndexTurn() + 1;
    int temp;
    for (int i = turnIdx, j = 6; i < j; i++, j--) {
        temp = game.getTurnList(i);
        game.setTurnList(i, game.getTurnList(j));
        game.setTurnList(j, temp);
    } 
}