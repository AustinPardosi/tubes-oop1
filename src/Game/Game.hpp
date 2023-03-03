// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "../AbilityCard/AbilityCard.hpp"
#include "../DeckCard/DeckCard.hpp"
#include "../CardTable/CardTable.hpp"
#include "../Player/Player.hpp"

class Game {
    public:
        // Konstruktor Game
        Game();
        
        // Member Function
        // Menjalankan Game
        void runGame();
        void action();

        // Menjalankan round robin
        int roundRobin(); // Mengubah isi turnList sesuai dengan aturan round robin
        // Jadi nanti pengaksesan current turn pemain tinggal iterasi array turnList yang isinya indeks pemain awal

        // Menambahkan player ke game
        void addPlayerToList();

        // Getter & Setter
        Player* getPlayerList();
        DeckCard getDeckCard();
        CardTable getCardTable();
        int getRound();
        float getBonusPoint();
        int getIndexTurn();
        int getPlayerTurn();
        int getTurnList(int);

        void setPlayerList(Player&);
        void setTurnList(int, int);
        void setDeckCard(DeckCard&);
        void setCardTable(CardTable&);
        void setRound(int);
        void setBonusPoint(float);
        void setIndexTurn();
        void setTurn(int);

    private:
        Player playerList[7];
        DeckCard deckCard;
        CardTable cardTable;
        int round = 1; 
        float bonusPoint;
        int* turnList; // Berisi dengan indeks pemain ketika awal diinisiasi
        int turn; // Diisi dengan indeks dari turnList
};

#endif