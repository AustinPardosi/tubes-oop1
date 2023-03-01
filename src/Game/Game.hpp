// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

<<<<<<< HEAD
<<<<<<< HEAD
// #include "../Inventory Holder/DeckCard.hpp"
// #include "../Inventory Holder/TableCard.hpp"
// #include "../Inventory Holder/Pemain.hpp"
#include "../AbilityCard/AbilityCard.hpp"
=======
#include "../Inventory Holder/DeckCard.hpp"
#include "../Inventory Holder/TableCard.hpp"
#include "../Inventory Holder/Pemain.hpp"
=======
#include "../DeckCard/DeckCard.hpp"
#include "../CardTable/CardTable.hpp"
#include "../Player/Player.hpp"
>>>>>>> 904ec04bf91a059483f3cb9b3199a2ba5d18445e
#include "../Ability Card/AbilityCard.hpp"
>>>>>>> f764f8617402b8a836c94ed120b93c39a7e8b538

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