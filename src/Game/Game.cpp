// Game.cpp
#include "Game.hpp" 
#include <math.h>

// Konstruktor Game
Game::Game() {
    this->round = 1; 
    this->turn = 0;
    this->bonusPoint = 0;
    this->turnList = {0,1,2,3,4,5,6};
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
    DeckCard temp;
    this->deckCard.addCards(temp);
    for_each(this->playerList.begin(), this->playerList.end(), [this] (Player& player) {
        player.addCards(this->deckCard);
        this->deckCard.removeCards(2);
    });  
    startRound();
}

void Game::startRound() {
    for_each(this->turnList.begin(), this->turnList.end(), [this] (int idx) {
        while (!this->playerList[idx].getAlreadyPlayed()) {
            try {
                this->playerList[idx].askForAction();
                if (this->playerList[idx].getCommandID() > 3) {
                    this->playerList[idx].setAbilityUsed(true);
                }
                this->commandList[this->playerList[idx].getCommandID()]->doCommand(*this);
                this->playerList[idx].setAlreadyPlayed(true);
            }
            catch (const char* err) {
                cout << err;
            }
        }
    });
}

void Game::resetGame() {
    this->turn = 0;
    roundRobin();
    this->bonusPoint = 64;
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        player.removeCards(2);
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

int Game::getCurrentPlayerTurn() {
    return this->turnList[this->turn];
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
    this->turn++;
}

void Game::doAbilityless() {
    
    this->turn++;
}

void Game::doQuadruple() {
    this->setBonusPoint(this->getBonusPoint() * 4) ;    
    this->turn++;
}

void Game::doQuarter() {
    this->setBonusPoint(this->getBonusPoint() / 4) ;    
    this->turn++;
}

void Game::doReroll() {
    
    this->turn++;
}

void Game::doSwap() {
    
    this->turn++;
}

void Game::doSwitch() {
    
    this->turn++;
}

void Game::doDouble() {
    this->setBonusPoint(this->getBonusPoint() * 2) ;    
    this->turn++;
}

void Game::doHalf() {
    this->setBonusPoint(this->getBonusPoint() / 2) ;    
    this->turn++;
}

void Game::doNext() {
    if (this->getIndexTurn() != 6) { // Jika turn belum mencapai pemain terakhir
        this->setTurn(this->getIndexTurn()+1);
    } 
    
    this->turn++;
    // Jika sudah mencapai pemain terakhir maka tidak lakukan apa2
    // Round robin akan dijalankan di Game
}
