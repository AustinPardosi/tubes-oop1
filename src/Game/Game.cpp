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
    roundRobin();
    this->bonusPoint = 64;
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        player.removeCards(0);
        player.removeCards(1);
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
    cout << this->playerList[this->turnList[this->turn]].getName() << " do DOUBLE!" << endl;
    cout << "The prize points goes up from " << initial << " to " << this->bonusPoint << "!" << endl;
    this->turn++;
}

void Game::doHalf() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do HALF!" << endl;
    if (this->bonusPoint == 1) {
        cout << "Uh-oh... no way! the prize points is already 1" << endl;
        cout << "The prize points does not change.. game continue!" << endl;
    }    
    else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 2;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << endl;
    }
    this->turn++;
}

void Game::doNext() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do NEXT!" << endl;
    cout << "The turn goes to the next player." << endl;
    this->turn++;
}

void Game::doReverse() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do REVERSE!" << endl;
    
    cout << "Remaining player's turn order: ";
    for_each(this->playerList.rbegin(), this->playerList.rbegin() + (7 - (this->turn+1)), [] (Player& player) {
        cout << player.getName() << " ";
    });
    cout << endl;

    reverse(this->turnList.begin(), this->turnList.begin() + this->turn + 1);
    reverse(this->turnList.begin() + this->turn + 1, turnList.end());

    cout << "Next round player's turn order: ";
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        cout << player.getName() << " ";
    });
    cout << endl;
}

void Game::doAbilityless() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " use ABILITY CARD!" << endl;
    // Instansiasi list pemain yang belum menggunakan kartunya
    int *listAbility = new int [7];
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (i != this->turn && !this->playerList[i].getAbilityUsed()) {
            listAbility[count] = i;
            count++;
        }
    }
    // Pemrosesan berdasar kasus
    if (count == 0) {
        cout << "Hmm.. seems like every player have used their ability card" << endl;
        cout << "Poor you :( you are now abilityless, this card becoming useless" << endl;
    } else {
        cout << "Please select the player whose ability card you want to turn off :" << endl;
        int countprint = 1;
        for (int i = 0; i < 7; i++) {
            if (i != this->turn) {
                cout << "  " << countprint << ". " << this->playerList[i].getName() << endl;
                countprint++;
            }
        }

        bool valid = false;
        string temp;
        int check;
        while (!valid) {
            try {
                cout << "Choose your option!" << endl;
                cout << ">> ";
                cin >> temp;

                if (!isdigit(temp) || (atoi(temp) > 0 && atoi(temp) < countprint)) {
                    InvalidInputException e;
                    throw e;
                } else {
                    if (countprint < this->turn) {
                        check = atoi(temp);
                    } else {
                        check = atoi(temp) + 1;
                    }
                    valid = true;
                }
            } 
            catch (InvalidInputException e) {
                e.printMessage();
            }
        }

        size_t myArraySize = sizeof(listAbility) / sizeof(int);
        int *end = listAbility + myArraySize;
        int *result = find(listAbility, end, check-1);
        // When the element is not found, std::find returns the end of the range
        if (result == end) {
            cout << "Sorry, " << this->playerList[check-1].getName() << " has already use his/her ability card" << endl;
            cout << "This card becoming useless :(" << endl;
        } else {
            this->playerList[check-1].setAbilityless(true);
            cout << this->playerList[check-1].getName() << "'s ability card has been turned off!" << endl;
        }
    }

    this->turn++;
}

void Game::doQuadruple() {
    long long initial = this->bonusPoint;
    this->bonusPoint *= 4;
    cout << this->playerList[this->turnList[this->turn]].getName() << " do QUADRUPLE!" << endl;
    cout << "The prize points goes up from " << initial << " to " << this->bonusPoint << "!" << endl;
    this->turn++;
}

void Game::doQuarter() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do QUARTER!" << endl;
    if (this->bonusPoint == 1) {
        cout << "Uh-oh... no way! the prize points is already 1" << endl;
        cout << "The prize points does not change.. game continue!" << endl;
    } else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 4;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << endl;
    }
         
    this->turn++;
}

void Game::doReroll() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do RE-ROLL";
    cout << "Throwing your cards out..." << endl;
    
    this->playerList[this->turnList[this->turn]].removeCards(0);
    this->playerList[this->turnList[this->turn]].removeCards(1);
    this->playerList[this->turnList[this->turn]].addCards(this->deckCard);
    this->deckCard.removeCards(2);
    
    cout << "You got 2 new cards :" << endl;
    this->playerList[this->turnList[this->turn]].showCards();
    this->turn++;
}

void Game::doSwap() {
    cout << "Please select the player whose card you want to exchange: " << endl;
    int countprint = 1;
    for (int i = 0; i < 7; i++) {
        if (i != this->turn) {
            cout << "  " << countprint << ". " << this->playerList[i].getName() << endl;
            countprint++;;
        }
    }

    bool valid = false;
    string temp;
    int player1;
    // while (!valid) {
    //     try {
    //         cout << "Choose your option!" << endl;
    //         cout << ">> ";
    //         cin >> temp;
    //         if (!isdigit(temp) || (atoi(temp) > 0 && atoi(temp) < countprint)) {
    //             InvalidInputException e;
    //             throw e;
    //         } else {
    //             if (countprint < this->turn) {
    //                 player1 = atoi(temp);
    //             } else {
    //                 player1 = atoi(temp) + 1;
    //             }
    //             valid = true;
    //         }
    //     } catch (InvalidInputException e) {
    //         e.printMessage();
    //     }
    // }

    cout << "Now please select another player whose card you want to exchange: " << endl;
    int countprint = 1;
    for (int i = 0; i < 7; i++) {
        if (i != this->turn && i != player1) {
            cout << "  " << countprint << ". " << this->playerList[i].getName() << endl;
            countprint++;
        }
    }

    bool valid = false;
    string temp;
    int player2;
    while (!valid) {
        try {
            cout << "Choose your option!" << endl;
            cout << ">> ";
            cin >> temp;

            if (!isdigit(temp) || (atoi(temp) > 0 && atoi(temp) < countprint)) {
                InvalidInputException e;
                throw e;
            } else {
                if (countprint < this->turn) {
                    player2 = atoi(temp);
                } else {
                    player2 = atoi(temp) + 1;
                }
                valid = true;
            }
        } catch (InvalidInputException e) {
            e.printMessage();
        }
    }
    
    cout << "Choose " << this->playerList[player1 - 1].getName() << "'s card" << endl;
    cout << "  1. Left" << endl;
    cout << "  2. Right" << endl;

    bool valid = false;
    string temp;
    int player1idx;
    while (!valid) {
        try {
            cout << "Choose your option!" << endl;
            cout << ">> ";
            cin >> temp;

            if (!isdigit(temp) || (atoi(temp) > 0 && atoi(temp) < countprint)) {
                InvalidInputException e;
                throw e;
            } else {
                player1idx = atoi(temp) - 1;
                valid = true;
            }
        } catch (InvalidInputException e) {
            e.printMessage();
        }
    }

    cout << "Now choose " << this->playerList[player2 - 1].getName() << "'s card" << endl;
    cout << "  1. Left" << endl;
    cout << "  2. Right" << endl;

    bool valid = false;
    string temp;
    int player2idx;
    while (!valid) {
        try {
            cout << "Choose your option!" << endl;
            cout << ">> ";
            cin >> temp;

            if (!isdigit(temp) || (atoi(temp) > 0 && atoi(temp) < countprint)) {
                InvalidInputException e;
                throw e;
            } else {
                player2idx = atoi(temp) - 1;
                valid = true;
            }
        } catch (InvalidInputException e) {
            e.printMessage();
        }
    }

    this->playerList[player1 - 1] + this->playerList[player2 - 1].getCard(player2idx);
    this->playerList[player2 - 1] + this->playerList[player1 - 1].getCard(player1idx);
    this->playerList[player1 - 1].removeCards(player1idx);
    this->playerList[player2 - 1].removeCards(player2idx);
    cout << "The card has already swapped!" << endl;

    this->turn++;
}


void Game::doSwitch() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do SWITCH!" << endl;
    cout << "Your current cards are: " << endl;
    this->playerList[this->turnList[this->turn]].showCards();

    vector<int> targetPlayer = this->turnList;
    targetPlayer.erase(targetPlayer.begin()+this->turn);
    sort(targetPlayer.begin(), targetPlayer.end());

    int count = 1;
    cout << "Please choose a player you want to switch with: " << endl;
    for_each(targetPlayer.begin(), targetPlayer.end(), [this, &i = count] (int idx) {
        cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
    });

    //bool valid = false;
    string temp;
    int choice;
    while (!valid) {
        try {
            cout << "Choose your option!" << endl;
            cout << ">> ";
            cin >> temp;

            if (!isdigit(temp) || (atoi(temp) > 0 && atoi(temp) <= targetPlayer.size())) {
                InvalidInputException e;
                throw e;
            }

            choice = atoi(temp);
            valid = true;
        } catch (InvalidInputException e) {
            e.printMessage();
        }
    }

    this->playerList[this->turnList[this->turn]].addCards(this->playerList[targetPlayer[choice]]);
    this->playerList[targetPlayer[choice]].addCards(this->playerList[this->turnList[this->turn]]);
    this->playerList[this->turnList[this->turn]].removeCards(0);
    this->playerList[this->turnList[this->turn]].removeCards(1);
    this->playerList[targetPlayer[choice]].removeCards(0);
    this->playerList[targetPlayer[choice]].removeCards(1);

    cout << "Two cards of " << this->playerList[this->turnList[this->turn]].getName() << " have been switched with " << this->playerList[targetPlayer[choice]].getName() << "'s hands" << endl;
    cout << "Your cards now are: "
    this->playerList[this->turnList[this->turn]].showCards();
    this->turn++;
}