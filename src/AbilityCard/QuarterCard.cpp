// File: QuarterCard.cpp
// Berisi implementasi dari kelas QuarterCard

#include "QuarterCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

QuarterCard::QuarterCard() {
    this->commandID = 6;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void QuarterCard::doCommand(Game& game) {
    game.doQuarter();
}