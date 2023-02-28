// File: Player.hpp
// Berisi deklarasi dari kelas Player

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Ability Card/AbilityCard.hpp"

class Player : public InventoryHolder {
    private:
        AbilityCard* ability;
        int currentPoin;
        bool alreadyPlayed;
        bool abilityless;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        Player();
        ~Player();
        Player operator=(const Player& other);

        /*--------------------------------------------------------------------*/
        /*---------------------GETTER AND SETTER SEGMENT----------------------*/
        
        /*--------------------------------------------------------------------*/
        /*------------------------ADDING CARDS SEGMENT------------------------*/
        void addCards(const InventoryHolder& other);
        Player operator+(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------REMOVING CARDS SEGMENT-----------------------*/
        void removeCards(int cardsRemoved);
        Player operator-(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------ASKING ACTION SEGMENT------------------------*/
        void askForAction();

        /*--------------------------------------------------------------------*/
        /*---------------------ADDITIONAL METHOD SEGMENT----------------------*/
        Player operator+(int poinHadiah);
        bool operator>(const Player& other);
        bool operator<(const Player& other);
        bool operator==(const Player& other);
};

#endif