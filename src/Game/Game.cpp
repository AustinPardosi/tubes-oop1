// Game.cpp
#include "Game.hpp" 
#include "../Command/Double.hpp"
#include "../Command/Half.hpp"
#include "../Command/Next.hpp"
#include "../Parsing/Parse.hpp"
#include "../AbilityCard/AbilitylessCard.hpp"
#include "../AbilityCard/QuadrupleCard.hpp"
#include "../AbilityCard/QuarterCard.hpp"
#include "../AbilityCard/RerollCard.hpp"
#include "../AbilityCard/ReverseCard.hpp"
#include "../AbilityCard/SwapCard.hpp"
#include "../AbilityCard/SwitchCard.hpp"
#include "../ExceptionHandling/BaseException.hpp"
#include "../ExceptionHandling/InvalidInputException.hpp"
using namespace std;

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Game::Game() {
    for (int i = 0; i < 7; i++) {
        this->playerList.push_back(Player());
    }

    this->turnList = {0,1,2,3,4,5,6};
    this->turn = 0;

    this->bonusPoint = 64;
    this->bet = 0;
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

Game::~Game() {
    for (int i = 0; i < this->commandList.size(); i++) {
        delete this->commandList[i];
    }
}

/*--------------------------------------------------------------------*/
/*---------------------------RUNNER SEGMENT---------------------------*/

void Game::start() {
    showSplashScreen();
    initializeGame();
    int count = 1;

    while (!(isPlayerWin())) {
        if (count > 1) {
            cout << endl;
        }
        cout << "\033[1;33m";
        cout << "===========           GAME " << count << "             ===========" << endl;
        cout << "\033[0m";
        startGame();
        count++;
        determineWinner();
        if (!isPlayerWin()) {
            resetGame();
        }
    }
    showLeaderboard();
}

void Game::startGame() {
    cout << "\033[33m";
    cout << "======        DETERMINE INPUT METHOD          ======" << endl;
    cout << "\033[0m";
    determineInputMethod();
    cout << "\033[33m";
    cout << "===========        BETTING TIME          ===========";
    cout << "\033[0m";
    long long bet;
    for_each(this->playerList.begin(), this->playerList.end(), [&b = bet, this] (Player& player) {
        player.addCards(this->deckCard);
        this->deckCard.removeCards(2);
        b = player.askForBet();
        this->bet += b;
    }); 

    cout << "\033[33m";
    cout << "\n================      ROUND 1      =================" << endl;
    cout << "\033[0m";
    startRound(1);
    giveAbility();
    for (int i = 2; i <= 6; i++) {
        cout << "\033[33m";
        cout << "\n================      ROUND " << i << "      =================" << endl;
        cout << "\033[0m";
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
    cout << "\033[1;33m";
    cout << "=========        INSERT PLAYER NAME         =========" << endl;
    cout << "\033[0m";
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
    this->bet = 0;
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

    cout << "\033[1;33m";
    cout << "\n===========        FINAL RESULT          ===========" << endl;
    cout << "\033[0m";
    cout << "The game ends!" << endl;
    cout << "\033[36m";
    cout << "Leaderboard: " << endl;
    int idx = 1;
    for_each(this->playerList.begin(), this->playerList.end(), [&i = idx] (const Player& player) {
        cout << "  " << i << ". " << player.getName() << ": " << player.getCurrentPoin() << endl;
        i++;
    });
    cout << "\033[0m";
    cout << endl << "\033[1;32m" << this->playerList[0].getName() << " won the game! Congratulations!\n" << "\033[0m" << endl;
}

void Game::determineInputMethod() {
    bool valid = false;
    string temp;
    
    while (!valid) {
        try {
            cout << "Please choose how to make the card arrangement!" << endl;
            cout << "  1. By file input" << endl;
            cout << "  2. Generate random cards" << endl;
            cout << "Choose your option!" << endl;
            cout << ">> " << "\033[34m";
            cin >> temp;
            cout << "\033[0m";

            if (!(!temp.empty() && all_of(temp.begin(), temp.end(), ::isdigit)) 
                 || (stoll(temp) < 0 || stoll(temp) > 2)) {
                InvalidInputException e;
                throw e;
            }
            valid = true;
        }
        catch (InvalidInputException e) {
            e.printMessage();
        }
    }

    // if by file input
    if (stoi(temp) == 1) {
        // Deklarasi variabek
        Parse p1;
        string inputfile;
        bool checkdone = false;

        // Proses validating
        while(!checkdone) {
            cout << "\033[36m" << "Input the file name" << endl;
            cout << "Input file format (52 cards) : <CardNumber> <ColorCode>" << "\033[0m" << endl;
            cout << ">> " << "\033[34m";
            cin >> inputfile;
            cout << "\033[0m";
            ifstream inputFile(inputfile);
            try {
                if(!inputFile.is_open()) {
                    throw new InvalidFileException;
                }
                checkdone = true;
            } catch (BaseException *e) {
                e->printMessage();
            }
        }

        p1.parsing(inputfile);
        vector<pair<int,int>> result = p1.getCards();
        vector<Card> cards;
        for (auto i : result) {
            Card card(i.second, i.first);
            cards.push_back(card);
        }

        this->deckCard = cards;
    } else {
        DeckCard temp;
        this->deckCard.addCards(temp);
    }
    cout << endl;
}

/*--------------------------------------------------------------------*/
/*--------------------WINNER DETERMINATION SEGMENT--------------------*/

// get the player with the highest combo, and give the prize point
void Game::determineWinner() {
    bool winnerDetermined = false;
    int counter=9;
    while (!winnerDetermined) {
        winnerDetermined = true;
        for_each(this->playerList.begin(),this->playerList.end(), [this,counter] (Player& p) {
            p.calculateCombo(this->cardTable.getListOfCard(),counter);
        });

        this->winner = getMax<Player>(this->playerList);
        // Periksa apakah ada yang seri
        for (int i=0; i<playerList.size(); i++) {
            if (i != winner && playerList[i] == playerList[winner]) {
                winnerDetermined = false;
                counter--;
                break;
            }
        }
    }
    this->playerList[this->winner] = this->playerList[this->winner] + (this->bonusPoint + this->bet);
    cout << "\033[1;33m";
    cout << "\n===========         GAME RESULT          ===========" << endl;
    cout << "\033[0m";
    cout << "\033[1;32m" << "The winner of the current game is " << this->playerList[this->winner].getName();
    cout << " with total point of " << this->playerList[this->winner].getCurrentPoin() << "\033[0m" << endl;
}


bool Game::isPlayerWin() {
    if (this->winner == -1) {
        return false;
    }
    else {
        long long win = 4294967296;
        return this->playerList[this->winner].getCurrentPoin() >= win;
    }
}

/*--------------------------------------------------------------------*/
/*----------------------COMMAND EXECUTION SEGMENT---------------------*/

void Game::doDouble() {
    long long initial = this->bonusPoint;
    this->bonusPoint *= 2;   
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do DOUBLE!" << endl;
    cout << "The prize points goes up from " << initial << " to " << this->bonusPoint << "!" << "\033[0m" << endl;
    this->turn++;
}

void Game::doHalf() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do HALF!" << endl;
    if (this->bonusPoint == 1) {
        cout << "Uh-oh... no way! the prize points is already 1" << endl;
        cout << "The prize points does not change.. game continue!" << "\033[0m" << endl;
    }    
    else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 2;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << "\033[0m" << endl;
    }
    this->turn++;
}

void Game::doNext() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do NEXT!" << endl;
    cout << "The turn goes to the next player." << "\033[0m" << endl;
    this->turn++;
}

void Game::doAbilityless() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " use ABILITYLESS!" << endl;
    // Instansiasi list pemain yang belum menggunakan kartunya
    vector<int> listAbility;
    for (int i = 0; i < 7; i++) {
        if (i != this->turnList[this->turn] && !this->playerList[i].getAbilityUsed()) {
            listAbility.push_back(i);
        }
    }

    // Pemrosesan berdasar kasus
    if (listAbility.size() == 0) {
        cout << "Hmm.. seems like every player have used their ability card" << endl;
        cout << "Poor you :( you are now abilityless, this card becoming useless" << "\033[0m"<< endl;
        this->playerList[this->turnList[this->turn]].setAbilityless(true);
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
        cout << "\033[0m";
    
        int check = validateInputNum(targetPlayer1.size()) - 1;

        // Mencari player untuk diubah
        cout << "\033[36m";
        if (this->playerList[targetPlayer1[check]].getAbilityUsed()) {
            cout << "Sorry, " << this->playerList[targetPlayer1[check]].getName() << " has already use his/her ability card" << endl;
            cout << "This card becoming useless :(" << "\033[0m" << endl;
        } else {
            this->playerList[targetPlayer1[check]].setAbilityless(true);
            cout << this->playerList[targetPlayer1[check]].getName() << "'s ability card has been turned off!" << "\033[0m" << endl;
        }
    }

    this->turn++;
}

void Game::doQuadruple() {
    long long initial = this->bonusPoint;
    this->bonusPoint *= 4;
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do QUADRUPLE!" << endl;
    cout << "The prize points goes up from " << initial << " to " << this->bonusPoint << "!" << "\033[0m" << endl;
    this->turn++;
}

void Game::doQuarter() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do QUARTER!" << endl;
    if (this->bonusPoint == 1) {
        cout << "Uh-oh... no way! the prize points is already 1" << endl;
        cout << "Prize points does not change.. the game continue!" << "\033[0m" << endl;
    } else {
        long long initial = this->bonusPoint;
        this->bonusPoint /= 4;
        cout << "The prize points goes down from " << initial << " to " << this->bonusPoint << "!" << "\033[0m" << endl;
    }
         
    this->turn++;
}

void Game::doReroll() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do RE-ROLL!" << endl;
    cout << "Throwing your cards out..." << endl;
    
    this->playerList[this->turnList[this->turn]].removeCards(0);
    this->playerList[this->turnList[this->turn]].removeCards(1);
    this->playerList[this->turnList[this->turn]].addCards(this->deckCard);
    this->deckCard.removeCards(2);
    
    cout << "You got 2 new cards :" << "\033[0m" << endl;
    this->playerList[this->turnList[this->turn]].showCards();
    this->turn++;
}

void Game::doReverse() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do REVERSE!" << endl;
    
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
    cout << "\033[0m" << endl;
}

void Game::doSwap() {
    vector<int> targetPlayer1 = this->turnList;
    targetPlayer1.erase(targetPlayer1.begin()+this->turn);
    sort(targetPlayer1.begin(), targetPlayer1.end());

    cout << "\033[36m" << "Please select the player whose card you want to exchange: " << endl;
    int count = 1;
    for_each(targetPlayer1.begin(), targetPlayer1.end(), [this, &i = count] (int idx) {
        cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
        i++;
    });
    cout << "\033[0m";
 
    int player1 = validateInputNum(targetPlayer1.size()) - 1;

    vector<int> targetPlayer2 = targetPlayer1;
    targetPlayer2.erase(targetPlayer2.begin() + player1);

    cout << "\033[36m" << "Now please select another player whose card you want to exchange: " << endl;
    count = 1;
    for_each(targetPlayer2.begin(), targetPlayer2.end(), [this, &i = count] (int idx) {
        cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
        i++;
    });
    cout << "\033[0m";

    int player2 = validateInputNum(targetPlayer2.size()) - 1;

    cout << "\033[36m" << "Choose " << this->playerList[targetPlayer1[player1]].getName() << "'s card" << endl;
    cout << "  1. Left" << endl;
    cout << "  2. Right" << "\033[0m" << endl;

    int player1idx = validateInputNum(2) - 1;

    cout << "\033[36m" << "Now choose " << this->playerList[targetPlayer2[player2]].getName() << "'s card" << endl;
    cout << "  1. Left" << endl;
    cout << "  2. Right" << "\033[0m" << endl;

    int player2idx = validateInputNum(2) - 1;

    this->playerList[targetPlayer1[player1]].swapCardWithOther(this->playerList[targetPlayer2[player2]], player1idx, player2idx);

    cout << "\033[36m" << "The card has been swapped" << "\033[0m" << endl;
    this->turn++;
}

void Game::doSwitch() {
    cout << "\033[36m" << this->playerList[this->turnList[this->turn]].getName() << " do SWITCH!" << endl;
    cout << "Your current cards are: " << "\033[0m" << endl;
    this->playerList[this->turnList[this->turn]].showCards();

    vector<int> targetPlayer = this->turnList;
    targetPlayer.erase(targetPlayer.begin()+this->turn);
    sort(targetPlayer.begin(), targetPlayer.end());

    int count = 1;
    cout << "\033[36m" << "Please choose a player you want to switch with: " << endl;
    for_each(targetPlayer.begin(), targetPlayer.end(), [this, &i = count] (int idx) {
        cout << "  " << i << ". " << this->playerList[idx].getName() << endl;
        i++;
    });
    cout << "\033[0m";

    int choice = validateInputNum(targetPlayer.size()) - 1;

    this->playerList[this->turnList[this->turn]].switchCardWithOther(this->playerList[targetPlayer[choice]]);

    cout << "\033[36m" << "Two cards of " << this->playerList[this->turnList[this->turn]].getName() << " have been switched with " << this->playerList[targetPlayer[choice]].getName() << "'s hands" << endl;
    cout << "Your cards now are: " << "\033[0m" << endl;
    this->playerList[this->turnList[this->turn]].showCards();
    this->turn++;
}

/*--------------------------------------------------------------------*/
/*---------------------------HELPING SEGMENT--------------------------*/

// show splash screen when game started
void Game::showSplashScreen() {
    cout << "\033[35m";
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
    cout << "\033[1;35m";
    cout << "     e88~-_                           888          " << endl;    
    cout << "    d888   \\   /~~~8e  888-~88e  e88~\\888 Y88b  /  " << endl;
    cout << "    8888           88b 888  888 d888  888  Y888/   " << endl;
    cout << "    8888      e88~-888 888  888 8888  888   Y8/    " << endl;
    cout << "    Y888   / C888  888 888  888 Y888  888    Y     " << endl;
    cout << "     e88_-~   /88_-888 888  888  e88_/888   /      " << endl;
    cout << "                                          _/       " << endl;
    cout << "     -   C  A  R  D      G  A  M  E   -            " << endl;
    cout << endl;
    cout << "\033[0m";
}

// Validasi angka input
int Game::validateInputNum(int size) {
    bool valid = false;
    string temp;

    while (!valid) {
        try {
            cout << "Choose your option!" << endl;
            cout << ">> " << "\033[34m";
            cin >> temp;
            cout << "\033[0m";

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