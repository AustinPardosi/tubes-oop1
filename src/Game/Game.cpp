// Game.cpp
#include "Game.hpp" 
#include <math.h>

// Konstruktor Game
Game::Game() {
    for (int i = 0; i < 7; i++) {
        this->playerList.push_back(Player());
    }

    this->turnList = {0,1,2,3,4,5,6};
    this->turn = 0;

    this->bonusPoint = 64;
    this->winner = -1;

    this->commandList.push_back(new Double());
    this->commandList.push_back(new Half());
    this->commandList.push_back(new Next());
    this->commandList.push_back(new AbilitylessCard());
    this->commandList.push_back(new QuadrupleCard());
    this->commandList.push_back(new QuarterCard());
    this->commandList.push_back(new RerollCard());
    this->commandList.push_back(new ReverseCard());
    this->commandList.push_back(new SwapCard());
    this->commandList.push_back(new SwitchCard());
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
    
    initializeGame();
    startRound(1);

    giveAbility();
    for (int i = 2; i <= 6; i++) {
        startRound(i);
    }

}

void Game::initializeGame() {
    int idx = 1;
    for_each(this->playerList.begin(), this->playerList.end(), [this, &i = idx] (Player& player) {
        bool valid = false;
        while (!valid) {
            try {
                player.askForName(i);
                valid = true;
            }
            catch (const char* err) {
                cout << err;
            }
        }
        player.addCards(this->deckCard);
        this->deckCard.removeCards(2);
        i++;
    }); 
}

void Game::giveAbility() {
    vector<int> abilityId = {4, 5, 6, 7, 8, 9, 10};
    mt19937::result_type seed = random_device()() ^ chrono::duration_cast<chrono::seconds>(
                                                    chrono::system_clock::now().time_since_epoch()).count();
    mt19937 gen(seed);
    shuffle(abilityId.begin(), abilityId.end(), gen);

    int idx = 0;
    for_each(abilityId.begin(), abilityId.end(), [this, &i = idx] (int id) {
        this->playerList[i].setAbilityID(id);
        i++;
    });
}

void Game::startRound(int round) {
    if (round != 6) {
        this->cardTable.addCards(this->deckCard);
        this->deckCard.removeCards(1);
    }

    for_each(this->turnList.begin(), this->turnList.end(), [this] (int idx) {
        while (!this->playerList[idx].getAlreadyPlayed()) {
            try {
                this->playerList[idx].askForAction();
                this->commandList[this->playerList[idx].getCommandID()-1]->doCommand(*this);
                if (this->playerList[idx].getCommandID() > 3) {
                    this->playerList[idx].setAbilityUsed(true);
                }
                if (this->playerList[idx].getCommandID() != 8) {
                    this->playerList[idx].setAlreadyPlayed(true);   
                }
            }
            catch (const char* err) {
                cout << err;
            }
        }
    });

    roundRobin();
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
    return this->playerList[winner].getCurrentPoin() >= pow(2, 32);
}

// Menjalankan round robin
void Game::roundRobin() {
    this->turn = 0; // Reset ulang indeks turn jadi 0
    this->turnList.push_back(this->turnList[0]);
    this->turnList.erase(this->turnList.begin());
}

// Ability pada game
void Game::doDouble() {
    long long initial = this->bonusPoint;
    this->bonusPoint *= 2;   
    this->turn++;
    cout << this->playerList[this->turn].getName() << " do DOUBLE!" << endl;
    cout << "The prize points goes up from " << initial << " to " << this->bonusPoint << "!" << endl;
}

void Game::doHalf() {
    if (this->bonusPoint == 1) {
        cout << "Uh-oh... no way! the prize points is already 1" << endl;
        cout << "The prize points does not change.. game continue!" << endl;
    }    
    else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 2;
        cout << this->playerList[this->turn].getName() << " do HALF!" << endl;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << endl;
    }
    this->turn++;
}

void Game::doNext() {
    this->turn++;
    cout << this->playerList[this->turn].getName() << " do NEXT!" << endl;
    cout << "The turn goes to the next player." << endl;
}

void Game::doReverse() {
    cout << this->playerList[this->turn].getName() << " do REVERSE!" << endl;
    
    cout << "Remaining player's turn order: ";
    for_each(this->playerList.rbegin(), this->playerList.rbegin() + (7 - (this->turn+1)), [] (Player& player) {
        cout << player.getName() << " ";
    });
    cout << endl;

    reverse(this->turnList.begin(), this->turnList.begin() + this->turn + 1);
    reverse(this->turnList.begin() + this->turn + 1, turnList.end());
    this->turn++;

    cout << "Next round player's turn order: ";
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        cout << player.getName() << " ";
    });
    cout << endl;
}

void Game::doAbilityless() {
    cout << this->playerList[this->turn].getName() << " use ABILITY CARD!" << endl;
    cout << "Please select the player whose ability card you want to turn off :" << endl;
    for (int i = 0; i < 7; i++) {
        if (i != this->turn) {
            cout << " " << i+1 << ". " << this->playerList[i].getName() << endl;
        }
    }
    this->turn++;
}

void Game::doQuadruple() {
    long long initial = this->bonusPoint;
    this->bonusPoint *= 4;
    this->turn++;
    cout << this->playerList[this->turn].getName() << " do QUADRUPLE!" << endl;
    cout << "The prize points goes up from " << initial << " to " << this->bonusPoint << "!" << endl;
}

void Game::doQuarter() {
    if (this->bonusPoint == 1) {
        cout << "Uh-oh... no way! the prize points is already 1" << endl;
        cout << "The prize points does not change.. game continue!" << endl;
    }    
    else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 4;
        cout << this->playerList[this->turn].getName() << "do QUARTER!" << endl;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << endl;
    }     
    this->turn++;
}

void Game::doReroll() {
    cout << "Do the RE-ROLL! throwing your cards..." << endl;
    cout << "You got 2 new cards :" << endl;
    this->turn++;
}

void Game::doSwap() {
    
    this->turn++;
}

void Game::doSwitch() {
    
    this->turn++;
}