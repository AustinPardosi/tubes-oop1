// File: ReverseCard.cpp
// Berisi implementasi dari kelas ReverseCard

#include "ReverseCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

ReverseCard::ReverseCard() {
    this->commandID = 8;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void ReverseCard::doCommand(Game& game) {
    game.doReverse();
}