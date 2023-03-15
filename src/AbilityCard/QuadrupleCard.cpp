// File: QuadrupleCard.cpp
// Berisi implementasi dari kelas QuadrupleCard

#include "QuadrupleCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

QuadrupleCard::QuadrupleCard() {
    this->commandID = 5;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void QuadrupleCard::doCommand(Game& game) {
    game.doQuadruple();
}