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

    public:  
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // ctor
        InventoryHolder();
        
        // dtor
        virtual ~InventoryHolder();

        /*--------------------------------------------------------------------*/
        /*-----------------------CARDS OPERATION SEGMENT----------------------*/
        
        // Add cards from another inventory to listOfCard
        // Implementation different for Player, DeckCard, and TableCard
        virtual void addCards (const InventoryHolder& other) = 0;

        // Remove cards from this inventory
        // Implementation different for Player, DeckCard, and TableCard
        virtual void removeCards(int cardsRemoved) = 0;
        
        /*--------------------------------------------------------------------*/
        /*---------------------ADDITIONAL METHOD SEGMENT----------------------*/

        // Get the first card in the listOfCard
        Card getFirstCard() const;

        // Show current cards in inventory
        void showCards() const;
};

#endif