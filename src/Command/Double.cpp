// File: Command.cpp
// Berisi implementasi dari kelas Double

#include <iostream>
#include "Double.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor double
Double::Double() {
    this->commandID = 1;
}

// Member Function
// Menjalankan command
void Double::doCommand(Game& game) {
    game.doDouble();
}