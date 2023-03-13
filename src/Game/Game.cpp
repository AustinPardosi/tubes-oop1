// Game.cpp
#include "Game.hpp" 
#include "../Command/Double.hpp"
#include "../Command/Half.hpp"
#include "../Command/Next.hpp"
#include "../AbilityCard/AbilitylessCard.hpp"
#include "../AbilityCard/QuadrupleCard.hpp"
#include "../AbilityCard/QuarterCard.hpp"
#include "../AbilityCard/RerollCard.hpp"
#include "../AbilityCard/ReverseCard.hpp"
#include "../AbilityCard/SwapCard.hpp"
#include "../AbilityCard/SwitchCard.hpp"
#include "../ExceptionHandling/BaseException.hpp"
#include "../ExceptionHandling/InvalidInputException.hpp"
#include <math.h>

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

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

/*--------------------------------------------------------------------*/
/*---------------------------RUNNER SEGMENT---------------------------*/

void Game::start() {
    showSplashScreen();
    initializeGame();
    int count = 1;
    while (!(this->isPlayerWin(this->winner))) {
        cout << "==================== GAME " << count << " =====================" << endl;
        this->startGame();
        count++;
        determineWinner();
        this->resetGame();
    }
    showLeaderboard();
}

void Game::startGame() {
    DeckCard temp;
    this->deckCard.addCards(temp);
    for_each(this->playerList.begin(), this->playerList.end(), [this] (Player& player) {
        player.addCards(this->deckCard);
        this->deckCard.removeCards(2);
    }); 

    cout << "==================== ROUND 1 ====================" << endl;
    startRound(1);
    giveAbility();
    for (int i = 2; i <= 6; i++) {
        cout << "\n==================== ROUND " << i << " ====================" << endl;
        startRound(i);
    }

}

void Game::startRound(int round) {
    if (round != 6) {
        this->cardTable.addCards(this->deckCard);
        this->deckCard.removeCards(1);
    }
    
    cout << "The cards on the table are: " << endl;
    this->cardTable.showCards();
    
    for_each(this->turnList.begin(), this->turnList.end(), [this, round] (int idx) {
        while (!this->playerList[idx].getAlreadyPlayed()) {
            try {
                this->playerList[idx].printInfo(round);
                this->playerList[idx].askForAction();
                this->commandList[this->playerList[idx].getCommandID()-1]->doCommand(*this);
                if (this->playerList[idx].getCommandID() > 3) {
                    this->playerList[idx].setAbilityUsed(true);
                }
                if (this->playerList[idx].getCommandID() != 8) {
                    this->playerList[idx].setAlreadyPlayed(true);   
                }
            }
            catch (BaseException* e) {
                e->printMessage();
            }
        }
    });

    roundRobin();
}

void Game::initializeGame() {
    int idx = 1;
    for_each(this->playerList.begin(), this->playerList.end(), [this, &i = idx] (Player& player) {
        player.askForName(i);
        cout << endl;
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

void Game::resetGame() {
    roundRobin();
    this->bonusPoint = 64;
    this->cardTable.removeCards(5);
    this->deckCard.clearCards();
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        player.removeCards(0);
        player.removeCards(0);
        player.setAbilityless(false);
        player.setAbilityUsed(false);
    });
}

void Game::roundRobin() {
    this->turn = 0; // Reset ulang indeks turn jadi 0
    this->turnList.push_back(this->turnList[0]);
    this->turnList.erase(this->turnList.begin());
    for_each(this->playerList.begin(), this->playerList.end(), [] (Player& player) {
        player.setAlreadyPlayed(false);
    });
}

void Game::showLeaderboard() {
    sort(this->playerList.begin(), this->playerList.end(), [] (const Player& p1, const Player& p2) {
        return p1.getCurrentPoin() > p2.getCurrentPoin();
    });

    cout << "The game ends!" << endl;
    cout << "Leaderboard: " << endl;
    int idx = 1;
    for_each(this->playerList.begin(), this->playerList.end(), [&i = idx] (const Player& player) {
        cout << "  " << i << ". " << player.getName() << ": " << player.getCurrentPoin() << endl;
        i++;
    });
    cout << this->playerList[0].getName() << " won the game!!" << endl;
}

/*--------------------------------------------------------------------*/
/*--------------------WINNER DETERMINATION SEGMENT--------------------*/

// get the player with the highest combo, and give the prize point
void Game::determineWinner() {
    for_each(this->playerList.begin(),this->playerList.end(), [this] (Player& p) {
        p.calculateCombo(this->cardTable.getListOfCard());
    });
    
    this->winner = getMax<Player>(this->playerList);
    this->playerList[this->winner] = this->playerList[this->winner] + this->bonusPoint;
}


bool Game::isPlayerWin(int winner) {
    return this->playerList[winner].getCurrentPoin() >= pow(2, 32);
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

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

void Game::doAbilityless() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " use ABILITYLESS!" << endl;
    // Instansiasi list pemain yang belum menggunakan kartunya
    vector<int> listAbility;
    for (int i = 0; i < 7; i++) {
        if (i != this->turn && !this->playerList[i].getAbilityUsed()) {
            listAbility.push_back(i);
        }
    }

    // Pemrosesan berdasar kasus
    if (listAbility.size() == 0) {
        cout << "Hmm.. seems like every player have used their ability card" << endl;
        cout << "Poor you :( you are now abilityless, this card becoming useless" << endl;
    } else {
        // Inisiasi list player
        vector<int> targetPlayer1 = this->turnList;
        targetPlayer1.erase(targetPlayer1.begin()+this->turn);
        sort(targetPlayer1.begin(), targetPlayer1.end());

        // Memilih player
        cout << "Please select the player whose ability card you want to turn off :" << endl;
        int count = 1;
        for_each(targetPlayer1.begin(), targetPlayer1.end(), [this, &i = count] (int idx) {
            cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
            i++;
        });
    
        int check = validateInputNum(targetPlayer1.size()) - 1;

        // Mencari player untuk diubah
        auto itr = find(listAbility.begin(), listAbility.end(), check);
        if (itr == listAbility.end()) {
            cout << "Sorry, " << this->playerList[targetPlayer1[check]].getName() << " has already use his/her ability card" << endl;
            cout << "This card becoming useless :(" << endl;
        } else {
            this->playerList[targetPlayer1[check]].setAbilityless(true);
            cout << this->playerList[targetPlayer1[check]].getName() << "'s ability card has been turned off!" << endl;
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
        cout << "Prize points does not change.. the game continue!" << endl;
    } else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 4;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << endl;
    }
         
    this->turn++;
}

void Game::doReroll() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do RE-ROLL!" << endl;
    cout << "Throwing your cards out..." << endl;
    
    this->playerList[this->turnList[this->turn]].removeCards(0);
    this->playerList[this->turnList[this->turn]].removeCards(1);
    this->playerList[this->turnList[this->turn]].addCards(this->deckCard);
    this->deckCard.removeCards(2);
    
    cout << "You got 2 new cards :" << endl;
    this->playerList[this->turnList[this->turn]].showCards();
    this->turn++;
}

void Game::doReverse() {
    cout << this->playerList[this->turnList[this->turn]].getName() << " do REVERSE!" << endl;
    
    cout << "Remaining player's turn order: ";
    for_each(this->turnList.rbegin(), this->turnList.rbegin() + (7 - (this->turn + 1)), [this] (int idx) {
        cout << this->playerList[idx].getName() << " ";
    });
    cout << endl;

    reverse(this->turnList.begin(), this->turnList.begin() + this->turn + 1);
    reverse(this->turnList.begin() + this->turn + 1, turnList.end());

    cout << "Next round player's turn order: ";
    for_each(this->turnList.begin()+1, this->turnList.end(), [this] (int idx) {
        cout << this->playerList[idx].getName() << " ";
    });
    cout << this->playerList[this->turnList[0]].getName();
    cout << endl;
}

void Game::doSwap() {
    vector<int> targetPlayer1 = this->turnList;
    targetPlayer1.erase(targetPlayer1.begin()+this->turn);
    sort(targetPlayer1.begin(), targetPlayer1.end());

    cout << "Please select the player whose card you want to exchange: " << endl;
    int count = 1;
    for_each(targetPlayer1.begin(), targetPlayer1.end(), [this, &i = count] (int idx) {
        cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
        i++;
    });
 
    int player1 = validateInputNum(targetPlayer1.size()) - 1;

    vector<int> targetPlayer2 = targetPlayer1;
    targetPlayer2.erase(targetPlayer2.begin() + player1);

    cout << "Now please select another player whose card you want to exchange: " << endl;
    count = 1;
    for_each(targetPlayer2.begin(), targetPlayer2.end(), [this, &i = count] (int idx) {
        cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
        i++;
    });

    int player2 = validateInputNum(targetPlayer2.size()) - 1;

    cout << "Choose " << this->playerList[targetPlayer1[player1]].getName() << "'s card" << endl;
    cout << "  1. Left" << endl;
    cout << "  2. Right" << endl;

    int player1idx = validateInputNum(2) - 1;

    cout << "Now choose " << this->playerList[targetPlayer2[player2]].getName() << "'s card" << endl;
    cout << "  1. Left" << endl;
    cout << "  2. Right" << endl;

    int player2idx = validateInputNum(2) - 1;

    this->playerList[targetPlayer1[player1]].swapCardWithOther(this->playerList[targetPlayer2[player2]], player1idx, player2idx);

    cout << "The card has been swapped" << endl;
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
        i++;
    });

    int choice = validateInputNum(targetPlayer.size()) - 1;

    this->playerList[this->turnList[this->turn]].switchCardWithOther(this->playerList[targetPlayer[choice]]);

    cout << "Two cards of " << this->playerList[this->turnList[this->turn]].getName() << " have been switched with " << this->playerList[targetPlayer[choice]].getName() << "'s hands" << endl;
    cout << "Your cards now are: " << endl;
    this->playerList[this->turnList[this->turn]].showCards();
    this->turn++;
}

/*--------------------------------------------------------------------*/
/*---------------------------HELPING SEGMENT--------------------------*/

// show splash screen when game started
void Game::showSplashScreen() {
    cout << "                                    .              " << endl;     
    cout << "                                  ../(#            " << endl;     
    cout << "                                   *.,             " << endl;     
    cout << "                                   ,..             " << endl;     
    cout << "                          ####*    *..             " << endl;     
    cout << "                   @.**************@./             " << endl;     
    cout << "                %*****************@.,&*&           " << endl;     
    cout << "              .*****,,*/(#&@@@&,,,,,,,,@,/         " << endl;     
    cout << "             #.,*#&@&&%##(((/////****(/(%%.        " << endl;     
    cout << "            %*****************************@        " << endl;     
    cout << "           ********************/((((/*****&        " << endl;     
    cout << "           %***************@.........../**%        " << endl;     
    cout << "          %*/**************,....    . .@/*%        " << endl;     
    cout << "          #***************/ ..........@***%        " << endl;     
    cout << "         #****************@........((/****%        " << endl;     
    cout << "         &***************/#....&**********%        " << endl;     
    cout << "         ******/*/********..,@************%        " << endl;     
    cout << "        @**/(%#/*********,#%#&###%********%        " << endl;     
    cout << "        ***####(**********(###&##(%*******%        " << endl;     
    cout << "       &**/####&*********/(###(%##&*******(        " << endl;     
    cout << "       (*###%##@*********/(#######%*******/        " << endl;     
    cout << "      ,** .*#(%%**********(###### .#*******.       " << endl;     
    cout << "      @ ..(***,,*********,#(####*&..@/******       " << endl;     
    cout << "    , ..&*****@**********,####&***%..%*****/       " << endl;
    cout << endl;
    cout << "     e88~-_                           888          " << endl;    
    cout << "    d888   \\   /~~~8e  888-~88e  e88~\\888 Y88b  /  " << endl;
    cout << "    8888           88b 888  888 d888  888  Y888/   " << endl;
    cout << "    8888      e88~-888 888  888 8888  888   Y8/    " << endl;
    cout << "    Y888   / C888  888 888  888 Y888  888    Y     " << endl;
    cout << "     e88_-~   /88_-888 888  888  e88_/888   /      " << endl;
    cout << "                                          _/       " << endl;
    cout << "     -   C  A  R  D      G  A  M  E   -            " << endl;
    cout << endl;
}


// Validasi angka input
int Game::validateInputNum(int size) {
    bool valid = false;
    string temp;

    while (!valid) {
        try {
            cout << "Choose your option!" << endl;
            cout << ">> ";
            cin >> temp;

            if (!(!temp.empty() && all_of(temp.begin(), temp.end(), ::isdigit)) 
                 || (stoi(temp) <= 0 || stoi(temp) > size)) {
                throw new InvalidInputException;
            }
            valid = true;  
        }
        catch (BaseException* e) {
            e->printMessage();
        }
    }

    return stoi(temp);
}