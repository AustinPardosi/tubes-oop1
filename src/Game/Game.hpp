// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

<<<<<<< HEAD
// #include "../Inventory Holder/DeckCard.hpp"
// #include "../Inventory Holder/TableCard.hpp"
// #include "../Inventory Holder/Pemain.hpp"
#include "../AbilityCard/AbilityCard.hpp"
=======
#include "../Inventory Holder/DeckCard.hpp"
#include "../Inventory Holder/TableCard.hpp"
#include "../Inventory Holder/Pemain.hpp"
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
        Pemain getPemain();
        DeckCard getDeckCard();
        TableCard getTableCard();
        int getRound();
        float getBonusPoint();
        int getTurn();

        void setPemain(Pemain&);
        void setDeckCard(DeckCard&);
        void setTableCard(TableCard&);
        void setRound(int);
        void setBonusPoint(float);
        void setTurn(int);

    private:
        Pemain pemain[7];
        DeckCard deckCard;
        TableCard tableCard;
        int round = 1; 
        float bonusPoint;
        int turn; // Diisi dengan id pemain saat ini, didapatkan dengan roundRobin()
};

#endif