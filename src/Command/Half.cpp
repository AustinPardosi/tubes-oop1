// File: Half.cpp
// Berisi implementasi dari kelas Half

#include <iostream>
#include "Half.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor half
Half::Half() {
    this->commandID = 2;
}

// Member Function
// Menjalankan command
void Half::doCommand(Game& game) {
    game.setBonusPoint(game.getBonusPoint() / 2) ;
}