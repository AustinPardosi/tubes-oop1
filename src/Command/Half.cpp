// File: Half.cpp
// Berisi implementasi dari kelas Half

#include "Half.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Half::Half() {
    this->commandID = 2;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void Half::doCommand(Game& game) {
    game.doHalf();
}