// File: Player.hpp
// Berisi deklarasi dari kelas Player

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../AbilityCard/AbilityCard.hpp"

class Player : public InventoryHolder {
    private:
        Command* action;
        AbilityCard* ability;
        int currentPoin;
        bool alreadyPlayed;
        bool abilityUsed;
        bool abilityless;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        Player();

        // cctor
        Player(const Player& other);

        // dtor
        ~Player();

        // operator=
        Player operator=(const Player& other);

        /*--------------------------------------------------------------------*/
        /*---------------------GETTER AND SETTER SEGMENT----------------------*/

        // get alreadyPlayed attribute;
        bool getAlreadyPlayed() const;

        // set alreadyPlayer attribute;
        void setAlreadyPlayed(bool alreadyPlayer);

        // get abilityUsed attribute;
        bool getAbilityUsed() const;

        // set abilityUsed attribute;
        void setAbilityUsed(bool abilityUsed);

        // get Abilityless attribute;
        bool getAbilityless() const;

        // set abilityless attribute;
        void setAbilityless(bool abilityless);
        
        /*--------------------------------------------------------------------*/
        /*------------------------ADDING CARDS SEGMENT------------------------*/
        
        // Add 2 card from the top of DeckCard to the Player hand
        void addCards(const InventoryHolder& other);

        // Return table card with 1 more card (other)
        Player operator+(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------REMOVING CARDS SEGMENT-----------------------*/
        
        // Remove the card at index cardsRemoved from the hand
        void removeCards(int cardsRemoved);

        // Return the player with card at index cardsRemoved removed
        Player operator-(int cardsRemoved);

        /*--------------------------------------------------------------------*/
        /*-----------------------ASKING ACTION SEGMENT------------------------*/
        void askForAction();

        /*--------------------------------------------------------------------*/
        /*---------------------POINT MANAGEMENT SEGMENT-----------------------*/
        Player operator+(int poinHadiah);


        /*--------------------------------------------------------------------*/
        /*---------------------ADDITIONAL METHOD SEGMENT----------------------*/
        bool operator>(const Player& other);
        bool operator<(const Player& other);
        bool operator==(const Player& other);
};

#endif