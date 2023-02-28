// Game.cpp
#include "Game.hpp"

// Konstruktor Game
Game::Game() {

}

// Member Function
// Menjalankan Game
void Game::runGame() {

}

void Game::action() {

}

// Menjalankan round robin
int Game::roundRobin() {

}

// Getter & Setter
Player* Game::getPlayerList() {
    return this->playerList;
}

DeckCard Game::getDeckCard() {
    return this->deckCard;
}

CardTable Game::getCardTable() {
    return this->cardTable;
}

int Game::getRound() {
    return this->round;
}

float Game::getBonusPoint() {
    return this->bonusPoint;
}

int Game::getTurn() {
    return this->turn;
}

void Game::setPlayerList(Player& playerList) {
    *this->playerList = playerList;
}

void Game::setDeckCard(DeckCard& dc) {
    this->deckCard = dc;
}

void Game::setCardTable(CardTable& tc) {
    this->cardTable = tc;
}

void Game::setRound(int round) {
    this->round = round;
}

void Game::setBonusPoint(float bonusPoint) {
    this->bonusPoint = bonusPoint;
}

void Game::setTurn(int turn) {
    this->turn = turn;
}