// File: Double.cpp
// Berisi implementasi dari kelas Double

#include "Double.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Double::Double() {
    this->commandID = 1;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void Double::doCommand(Game& game) {
    game.doDouble();
}