// File: Next.cpp
// Berisi implementasi dari kelas Next

#include <iostream>
#include "Next.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor next
Next::Next() {
    this->commandID = 3;
}

// Member Function
// Menjalankan command
void Next::doCommand(Game& game) {
    game.doNext();
}