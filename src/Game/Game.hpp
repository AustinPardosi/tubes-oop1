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

#include "../ExceptionHandling/BaseException.hpp"
#include "../ExceptionHandling/InvalidInputException.hpp"

class Game {
    private:
        DeckCard deckCard;
        CardTable cardTable;

        vector<Player> playerList;
        vector<int> turnList;
        int turn;

        vector<Command*> commandList;
        long long bonusPoint;
        int winner;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // constructor of game object
        Game();
        
        /*--------------------------------------------------------------------*/
        /*---------------------------RUNNER SEGMENT---------------------------*/
        
        // start the entire game and organize other object
        void start();

        // start 1 game (initialize, give ability, and start 6 round)
        void startGame();

        // start one round, asking for command from player and execute it
        void startRound(int);

        // ask the name of players
        void initializeGame();

        // assign ability to every player randomly
        void giveAbility();

        // reset the prize point and state of player, do round robin
        void resetGame();

        // change the turn of play by round robin rule
        void roundRobin(); 

        // show the leaderboard of final result
        void showLeaderboard();

        /*--------------------------------------------------------------------*/
        /*--------------------WINNER DETERMINATION SEGMENT--------------------*/

        // get the player with the highest combo, and give the prize point
        void determineWinner();

        // check if the player that get the prize point win the game or not
        bool isPlayerWin(int);

        /*--------------------------------------------------------------------*/
        /*----------------------COMMAND EXECUTION SEGMENT---------------------*/

        // do the double command
        void doDouble();

        // do the half command
        void doHalf();

        // do the next command
        void doNext();

        // do the abilityless ability
        void doAbilityless();

        // do the quadruple ability
        void doQuadruple();

        // do the quarter ability
        void doQuarter();

        // do the reroll ability
        void doReroll();

        // do the reverse ability
        void doReverse();

        // do the swap ability
        void doSwap();
        
        // do the switch ability
        void doSwitch();

        /*--------------------------------------------------------------------*/
        /*---------------------------HELPING SEGMENT--------------------------*/
        
        // show splash screen when game started
        void showSplashScreen();
        
        // ask for user input and validate them to between 1 and the parameter
        int validateInputNum(int);
};

#endif