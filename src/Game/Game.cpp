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
Pemain Game::getPemain() {
    return this->pemain;
}

DeckCard Game::getDeckCard() {
    return this->deckCard;
}

TableCard Game::getTableCard() {
    return this->TableCard;
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

void Game::setPemain() {
    this->(*pemain);
}

void Game::setDeckCard(DeckCard& dc) {
    this->deckCard = dc;
}

void Game::setTableCard(TableCard& tc) {
    this->TableCard = tc;
}

void Game::setRound(int round) {
    this->round = round;
}

void setBonusPoint(float bonusPoint) {
    this->bonusPoint = bonusPoint;
}

void Game::setTurn(int turn) {
    this->turn = turn;
}