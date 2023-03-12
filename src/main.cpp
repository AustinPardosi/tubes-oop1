// Konsepnya nyobain bikin main

#include <iostream>
#include "AbilityCard/AbilityCard.hpp"
#include "AbilityCard/ReverseCard.hpp"
#include "Card/Card.hpp"
#include "CardTable/CardTable.hpp"
#include "Command/Command.hpp"
#include "DeckCard/DeckCard.hpp"
#include "Game/Game.hpp"
#include "InventoryHolder/InventoryHolder.hpp"
#include "Player/Player.hpp"

int main() {
    Game *g = new Game();
    // ReverseCard *rc = new ReverseCard();
    // vector<int> turnList = g->getTurnList();
    cout << "Giliran pemain" << g->getCurrentPlayerTurn() << endl;
    // g->roundRobin();
    // cout << "Giliran pemain" << g->getPlayerTurn() << endl;
    return 0;
}

// Command compile
// g++ AbilityCard/AbilityCard.cpp AbilityCard/ReverseCard.cpp Card/Card.cpp CardTable/CardTable.cpp Command/Command.cpp DeckCard/DeckCard.cpp Game/Game.cpp InventoryHolder/InventoryHolder.cpp Player/Player.cpp main.cpp -o main