// Game.cpp
#include "Game.hpp" 
#include <math.h>

// Konstruktor Game
Game::Game() {
    this->round = 1; 
    this->bonusPoint = 0;
    this->turnList = {0,1,2,3,4,5,6};
    this->turn = 0;
    this->winner = -1;
}

// Member Function
// Menjalankan Game
void Game::start() {
    while (!(this->isPlayerWin(this->winner))) {
        // loop sampai ada yang menang

        this->startGame();
        
        this->resetGame(); // reset game

    }
}

void Game::startGame() {

}

void Game::startRound() {
    
}

void Game::resetGame() {
    roundRobin();
    this->bonusPoint = 64;
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        player.setAlreadyPlayed(false);
        player.setAbilityless(false);
        player.setAbilityUsed(false);
    });
}

bool Game::isPlayerWin(int& winner) {
    for (int i = 0; i < 7; i++) {
        if (this->getPlayerByIdx(i).getCurrentPoin() >= pow(2,32)) {
            winner = i;
            return true;
        } 
    }
}

// Menjalankan round robin
void Game::roundRobin() {
    this->turn = 0; // Reset ulang indeks turn jadi 0
    this->round++; // Mengubah nilai round yang sudah dimainkan
    this->turnList.push_back(this->turnList[0]);
    this->turnList.erase(this->turnList.begin());
}

void Game::addPlayerToList() {
    for (int i = 0; i < 6; i++) {
        Player* player = new Player();
        this->playerList.push_back(*player);
    }
}

// Getter & Setter
vector<Player> Game::getPlayerList() {
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

int Game::getCurrentPlayerTurn() {
    // Mendapatkan indeks pemain yang bermain pada turn saat ini
    return this->turnList[this->turn];
}

int Game::getTurnListByIdx(int idx) {
    // Mengakses turnList dengan indeks idx
    return this->turnList[idx];
}

Player Game::getPlayerByIdx(int idx) {
    // Mengakses turnList dengan indeks idx
    return this->playerList[idx];
}

vector<int> Game::getTurnList() {
    // Mengakses turnList
    return this->turnList;
}

void Game::setPlayerList(Player& playerList) {
    this->playerList[getCurrentPlayerTurn()] = playerList;
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

// Ability pada game
void Game::doReverse() {
    vector <int> turnList = this->getTurnList();
    reverse(turnList.begin(), turnList.begin() + this->getCurrentPlayerTurn() + 1);
    reverse(turnList.begin() + this->getCurrentPlayerTurn() + 1, turnList.end());
    turn++;
}

void Game::doAbilityless() {
    
    turn++;
}

void Game::doQuadruple() {
    this->setBonusPoint(this->getBonusPoint() * 4) ;    
    turn++;
}

void Game::doQuarter() {
    this->setBonusPoint(this->getBonusPoint() / 4) ;    
    turn++;
}

void Game::doReroll() {
    
    turn++;
}

void Game::doSwap() {
    
    turn++;
}

void Game::doSwitch() {
    
    turn++;
}

void Game::doDouble() {
    this->setBonusPoint(this->getBonusPoint() * 2) ;    
    turn++;
}

void Game::doHalf() {
    this->setBonusPoint(this->getBonusPoint() / 2) ;    
    turn++;
}

void Game::doNext() {
    if (this->getIndexTurn() != 6) { // Jika turn belum mencapai pemain terakhir
        this->setTurn(this->getIndexTurn()+1);
    } 
    
    turn++;    
    // Jika sudah mencapai pemain terakhir maka tidak lakukan apa2
    // Round robin akan dijalankan di Game
}
