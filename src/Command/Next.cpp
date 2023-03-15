// File: Next.cpp
// Berisi implementasi dari kelas Next

#include "Next.hpp"
#include "../Game/Game.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Next::Next() {
    this->commandID = 3;
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void Next::doCommand(Game& game) {
    game.doNext();
}