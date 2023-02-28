// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "../DeckCard/DeckCard.hpp"
#include "../CardTable/CardTable.hpp"
#include "../Player/Player.hpp"
#include "../Ability Card/AbilityCard.hpp"

class Game {
    public:
        // Konstruktor Game
        Game();
        
        // Member Function
        // Menjalankan Game
        void runGame();
        void action();

        // Menjalankan round robin
        int roundRobin();
        
        // Getter & Setter
        Player* getPlayerList();
        DeckCard getDeckCard();
        CardTable getCardTable();
        int getRound();
        float getBonusPoint();
        int getTurn();

        void setPlayerList(Player&);
        void setDeckCard(DeckCard&);
        void setCardTable(CardTable&);
        void setRound(int);
        void setBonusPoint(float);
        void setTurn(int);

    private:
        Player playerList[7];
        DeckCard deckCard;
        CardTable cardTable;
        int round = 1; 
        float bonusPoint;
        int turn; // Diisi dengan id Player saat ini, didapatkan dengan roundRobin()
};

#endif