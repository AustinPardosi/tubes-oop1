// Game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
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

        // Menjalankan round robin
        void roundRobin(); // Mengubah isi turnList sesuai dengan aturan round robin
        // Jadi nanti pengaksesan current turn pemain tinggal iterasi array turnList yang isinya indeks pemain awal

        // Menambahkan player ke game
        void addPlayerToList();

        // Mengecek apakah ada player yang sudah menang dan mengeluarkan pemenangnya
        bool isPlayerWin(int&);

        // Getter & Setter
        vector<Player> getPlayerList();
        DeckCard getDeckCard();
        CardTable getCardTable();
        int getRound();
        float getBonusPoint();
        int getIndexTurn();
        int getCurrentPlayerTurn();
        vector<int> getTurnList();
        Player getPlayerByIdx(int);
        int getTurnListByIdx(int);

        void setPlayerList(Player&);
        void setTurnList(int, int);
        void setDeckCard(DeckCard&);
        void setCardTable(CardTable&);
        void setRound(int);
        void setBonusPoint(float);
        void setIndexTurn();
        void setTurn(int);

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
        vector<Player> playerList;
        DeckCard deckCard;
        CardTable cardTable;
        int round = 1; 
        long long bonusPoint; 
        vector <int> turnList; // Berisi dengan indeks pemain ketika awal diinisiasi
        int turn; // Diisi dengan indeks dari turnList
        vector<Command*> commandList;
        int winner;
};

#endif