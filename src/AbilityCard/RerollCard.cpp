// File: RerollCard.cpp
// Berisi implementasi dari kelas RerollCard

#include "RerollCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

RerollCard::RerollCard() {
    this->commandID = 7;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void RerollCard::doCommand(Game& game) {
    game.doReroll();
}