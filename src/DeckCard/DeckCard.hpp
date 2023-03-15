// File: DeckCard.hpp
// Berisi deklarasi dari kelas DeckCard

#ifndef DECKCARD_HPP
#define DECKCARD_HPP

#include "../InventoryHolder/InventoryHolder.hpp"

class DeckCard : public InventoryHolder {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        DeckCard();

        // user-defined ctor: copy the listOfCard to this object listOfCard attribute
        DeckCard(const vector<Card>& listOfCard);

        // dtor
        ~DeckCard();

        // operator= 
        DeckCard& operator=(const DeckCard& other);

        /*--------------------------------------------------------------------*/
        /*------------------------ADDING CARDS SEGMENT------------------------*/
        
        // generate all 52 cards randomly
        void addCards(const InventoryHolder& other);

        // function overloading to add cards by file
        void addCards(string);

        // return deck card with 1 more card (other)
        DeckCard operator+(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------REMOVING CARDS SEGMENT-----------------------*/

        // remove the first <cardsRemoved> cards from the deck
        void removeCards(int cardsRemoved);

        // return deck card with <cardsRemoved> less card
        DeckCard operator-(int cardsRemoved);

        // clear all cards from the deck
        void clearCards();
};

#endif