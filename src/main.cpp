// File : main.cpp
// Menginisiasi objek Game dan memulai permainan

// Command compile
// g++ AbilityCard/AbilityCard.cpp AbilityCard/ReverseCard.cpp Card/Card.cpp CardTable/CardTable.cpp Command/Command.cpp DeckCard/DeckCard.cpp Game/Game.cpp InventoryHolder/InventoryHolder.cpp Player/Player.cpp main.cpp -o main

#include "Game/Game.hpp"

int main() {
    Game g;
    g.start();
    return 0;
}