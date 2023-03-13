// File: CardTable.hpp
// Berisi deklarasi dari kelas CardTable

#ifndef CARDTABLE_HPP
#define CARDTABLE_HPP

#include "../InventoryHolder/InventoryHolder.hpp"

class CardTable : public InventoryHolder {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        CardTable();

        // user-defined ctor: copy the listOfCard to this object listOfCard attribute
        CardTable(const vector<Card>& listOfCard);

        // dtor
        ~CardTable();

        // operator=
        CardTable& operator=(const CardTable& other);

        /*--------------------------------------------------------------------*/
        /*------------------------ADDING CARDS SEGMENT------------------------*/

        // Add 1 card from the top of DeckCard to the CardTable
        void addCards(const InventoryHolder& other);

        // Return table card with 1 more card (other)
        CardTable operator+(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------REMOVING CARDS SEGMENT-----------------------*/

        // Remove all cards from the table to start new game
        void removeCards(int cardsRemoved);

        /*--------------------------------------------------------------------*/
        /*-----------------------GETTER SETTER SEGMENT------------------------*/

        // Return the cards on the table
        vector<Card> getListOfCard();

};

#endif