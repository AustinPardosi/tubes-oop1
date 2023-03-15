// File: SwapCard.cpp
// Berisi implementasi dari kelas SwapCard

#include "SwapCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

SwapCard::SwapCard() {
    this->commandID = 9;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void SwapCard::doCommand(Game& game) {
    game.doSwap();
}