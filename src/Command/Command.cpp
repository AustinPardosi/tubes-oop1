// File: Command.cpp
// Berisi implementasi dari kelas Command

#include <iostream>
#include "Command.hpp"
#include "../Game/Game.hpp"
using namespace std;

// Konstruktor command
Command::Command() {
    this->commandID = 0;
}