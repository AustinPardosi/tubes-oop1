// File : main.cpp
// Menginisiasi objek Game dan memulai permainan

// Command compile
// g++ Combination/*.cpp Card/*.cpp InventoryHolder/*.cpp CardTable/*.cpp DeckCard/*.cpp Player/*.cpp Command/*.cpp AbilityCard/*.cpp ExceptionHandling/*.cpp Game/*.cpp main.cpp -o ../bin/main

#include "Game/Game.hpp"

int main() {
    Game g;
    g.start();
    return 0;
}