// File: InventoryHolder.hpp
// Berisi deklarasi dari kelas InventoryHolder

#ifndef INVENTORYHOLDER_HPP
#define INVENTORYHOLDER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "../Card/Card.hpp"

class InventoryHolder {
    protected:
        vector<Card> listOfCard;
        string cardLine[4];

    public:  
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        InventoryHolder();
        
        // dtor
        virtual ~InventoryHolder();

        /*--------------------------------------------------------------------*/
        /*-----------------------CARDS OPERATION SEGMENT----------------------*/
        
        // add cards from another inventory to listOfCard
        // implementation different for Player, DeckCard, and TableCard
        virtual void addCards (const InventoryHolder& other) = 0;

        // remove cards from this inventory
        // implementation different for Player, DeckCard, and TableCard
        virtual void removeCards(int cardsRemoved) = 0;
        
        /*--------------------------------------------------------------------*/
        /*---------------------ADDITIONAL METHOD SEGMENT----------------------*/

        // get the card at the index position in the listOfCard
        Card getCard(int index) const;

        // setup the element of card to print
        void cardSetup(int nums);

        // show current cards in inventory
        void showCards();
};

#endif