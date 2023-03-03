// Game.cpp
#include "Game.hpp"

// Konstruktor Game
Game::Game() {
    Player playerList[7];
    DeckCard deckCard;
    CardTable cardTable;
    int round = 1; 
    float bonusPoint = 0;
    int turnList[] = {0,1,2,3,4,5,6};
    int turn = 0;
}

// Member Function
// Menjalankan Game
void Game::runGame() {

}

void Game::action() {

}

// Menjalankan round robin
int Game::roundRobin() {
    this->turn = 0; // Reset ulang indeks turn jadi 0
    this->round++; // Mengubah nilai round yang sudah dimainkan
    int temp = this->turnList[0];
    for (int i = 0; i < 6; i++) {
        this->turnList[i] = this->turnList[i+1];
    }
    this->turnList[6] = temp;
}

void Game::addPlayerToList() {
    for (int i = 0; i < 6; i++) {
        Player* player = new Player();
        this->playerList[i] = *player;
    }
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

int Game::getIndexTurn() {
    // Mendapatkan jumlah turn ke berapa pada round saat ini
    return this->turn;
};

int Game::getPlayerTurn() {
    // Mendapatkan indeks pemain yang bermain pada turn saat ini
    return this->turnList[this->turn];
}

int Game::getTurnList(int idx) {
    // Mengakses turnList dengan indeks idx
    return this->turnList[idx];
}

void Game::setPlayerList(Player& playerList) {
    *this->playerList = playerList;
}

void Game::setTurnList(int idx, int val) {
    this->turnList[idx] = val;
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

// Member Function
// Menggunakan kartu yang dimiliki
void doCommand(Game& game) {
    int turnIdx = game.getIndexTurn() + 1;
    int temp;
    for (int i = turnIdx, j = 6; i < j; i++, j--) {
        temp = game.getTurnList(i);
        game.setTurnList(i, game.getTurnList(j));
        game.setTurnList(j, temp);
    }
}