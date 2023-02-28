// Half.hpp
#ifndef COMMAND_HALF_HPP
#define COMMAND_HALF_HPP

// #include "../Inventory Holder/DeckCard.hpp"
// #include "../Inventory Holder/TableCard.hpp"
// #include "../Inventory Holder/Pemain.hpp"
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
        // Pemain getPemain();
        // DeckCard getDeckCard();
        // TableCard getTableCard();
        int getRound();
        float getBonusPoint();
        int getTurn();

        // void setPemain();
        // void setDeckCard();
        // void setTableCard();
        void setRound(int);
        // void setBonusPoint(Action);
        void setTurn(int);

    private:
        // Pemain pemain[7];
        // DeckCard deckCard;
        // TableCard tableCard;
        int round = 1; 
        float bonusPoint;
        int turn; // Diisi dengan id pemain saat ini, didapatkan dengan roundRobin()
};

#endif