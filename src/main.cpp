// File : main.cpp
// Menginisiasi objek Game dan memulai permainan

// Command compile
// g++ AbilityCard/*.cpp Card/*.cpp CardTable/*.cpp Combination/*.cpp Command/*.cpp DeckCard/*.cpp ExceptionHandling/*.cpp Game/*.cpp Helper/*.cpp InventoryHolder/*.cpp Player/*.cpp main.cpp -o main

#include "Game/Game.hpp"

int main() {
    Game g;
    g.start();
    return 0;
}