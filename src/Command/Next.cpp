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
    if (game.getIndexTurn() != 6) { // Jika turn belum mencapai pemain terakhir
        game.setTurn(game.getIndexTurn()+1);
    } 

    // Jika sudah mencapai pemain terakhir maka tidak lakukan apa2
    // Round robin akan dijalankan di Game
}