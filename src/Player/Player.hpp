// File: Player.hpp
// Berisi deklarasi dari kelas Player

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <map>

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Combination/Combination.hpp"

class Player : public InventoryHolder {
    private:
        string name;
        int commandId;
        int abilityId;
        long long currentPoin;
        bool alreadyPlayed;
        bool abilityUsed;
        bool abilityless;
        vector<Combination*> currCombo;
        Combination* maxCombo;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        Player();

        // user-defined ctor
        Player(vector<Card> listCards, string name, int commandId, int abilityId, long long currentPoin, bool alreadyPlayed, bool abilityUsed, bool abilityless);

        // cctor
        Player(const Player& other);

        // dtor
        ~Player();

        // operator=
        Player& operator=(const Player& other);

        /*--------------------------------------------------------------------*/
        /*---------------------GETTER AND SETTER SEGMENT----------------------*/

        // ask for name of player
        void askForName(int i);

        // get player name
        string getName() const;

        // get listCard
        vector<Card> getCardList() const;

        // set listCard
        void setCardList(vector<Card>);

        // set ability id
        void setAbilityID(int abilityId);

        // get alreadyPlayed attribute        
        bool getAlreadyPlayed() const;

        // set alreadyPlayed attribute;
        void setAlreadyPlayed(bool alreadyPlayer);

        // get abilityUsed attribute;
        bool getAbilityUsed() const;

        // set abilityUsed attribute;
        void setAbilityUsed(bool abilityUsed);

        // get Abilityless attribute;
        bool getAbilityless() const;

        // set abilityless attribute;
        void setAbilityless(bool abilityless);

        // get currentPoin attribute;
        long long getCurrentPoin() const;

        // get commandID attribute;
        int getCommandID() const;
        
        /*--------------------------------------------------------------------*/
        /*------------------------ADDING CARDS SEGMENT------------------------*/
        
        // add 2 card from the top of DeckCard to the Player hand
        void addCards(const InventoryHolder& other);

        // return table card with 1 more card (other)
        Player operator+(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------REMOVING CARDS SEGMENT-----------------------*/
        
        // remove the card at index cardsRemoved from the hand
        void removeCards(int cardsRemoved);

        // return the player with card at index cardsRemoved removed
        Player operator-(int cardsRemoved);

        /*--------------------------------------------------------------------*/
        /*-----------------------ASKING ACTION SEGMENT------------------------*/
        
        // fill list of commands with pair<string, int>
        void fillMapsOfCommand(map<string, int>& listCommands);

        // ask for player action, throw exception if not valid
        void askForAction();

        /*--------------------------------------------------------------------*/
        /*----------------------SWAP AND SWITCH SEGMENT-----------------------*/
        
        // the player switch one of their card with other player
        void swapCardWithOther(Player& other, int handPos, int otherPos);

        // switch the player entire hand with other player
        void switchCardWithOther(Player& other);

        /*--------------------------------------------------------------------*/
        /*--------------------------COMBO SEGMENT-----------------------------*/
        
        // calculate the player highest combo with the cards on the table
        void calculateCombo(vector<Card>,int);

        /*--------------------------------------------------------------------*/
        /*---------------------POINT MANAGEMENT SEGMENT-----------------------*/
        
        // asking how many points player want to bet
        long long askForBet();

        // add the prize point to player own point
        Player operator+(long long poinHadiah);

        /*--------------------------------------------------------------------*/
        /*---------------------ADDITIONAL METHOD SEGMENT----------------------*/
        
        // check if player combo is higher than other player
        bool operator>(const Player& other);

        // check if player combo is lower than other player
        bool operator<(const Player& other);

        // check if player combo is the same as other player
        bool operator==(const Player& other);

        // show player cards, ability, point, and name
        void printInfo(int);
};

#endif