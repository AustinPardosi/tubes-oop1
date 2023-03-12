// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <iostream>
using namespace std;

#include "../Command/Command.hpp"
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

#include "../DeckCard/DeckCard.hpp"
#include "../CardTable/CardTable.hpp"
#include "../Player/Player.hpp"

#include "../ExceptionHandling/InvalidInputException.hpp"

class Game {
    public:
        // Konstruktor Game
        Game();
        
        // Member Function
        // Menjalankan Game dan round
        void start();
        void startGame();

        void initializeGame();
        void giveAbility();
        void startRound(int);

        // Mereset poin hadiah, turn, dan melakukan round robin
        void resetGame();

        // Menjalankan round robin
        void roundRobin(); // Mengubah isi turnList sesuai dengan aturan round robin
        // Jadi nanti pengaksesan current turn pemain tinggal iterasi array turnList yang isinya indeks pemain awal

        // Mengecek apakah ada player yang sudah menang dan mengeluarkan pemenangnya
        bool isPlayerWin(int&);

        // Ability pada game
        void doReverse();
        void doAbilityless();
        void doQuadruple();
        void doQuarter();
        void doReroll();
        void doSwap();
        void doSwitch();
        void doDouble();
        void doHalf();
        void doNext();

    private:
        DeckCard deckCard;
        CardTable cardTable;

        vector<Player> playerList;
        vector <int> turnList; // Berisi dengan indeks pemain ketika awal diinisiasi
        int turn;

        vector<Command*> commandList;
        long long bonusPoint;
        int winner;

        int validateInputNum(int);
};

#endif