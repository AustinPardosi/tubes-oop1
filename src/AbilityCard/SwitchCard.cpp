// File: SwitchCard.cpp
// Berisi implementasi dari kelas SwitchCard

#include "SwitchCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

SwitchCard::SwitchCard() {
    this->commandID = 10;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void SwitchCard::doCommand(Game& game) {
    game.doSwitch();
}