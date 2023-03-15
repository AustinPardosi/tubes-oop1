// File: AbilitylessCard.cpp
// Berisi implementasi dari kelas AbilitylessCard

#include "AbilitylessCard.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

AbilitylessCard::AbilitylessCard() {
    this->commandID = 4;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void AbilitylessCard::doCommand(Game& game) {
    game.doAbilityless();
}