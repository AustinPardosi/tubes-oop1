// File: DeckCard.hpp
// Berisi deklarasi dari kelas DeckCard

#ifndef DECKCARD_HPP
#define DECKCARD_HPP

#include <chrono>
#include <random>
#include <map>

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
        
        // Generate all 52 cards randomly
        void addCards(const InventoryHolder& other);

        // Return deck card with 1 more card (other)
        DeckCard operator+(const Card& other);

        /*--------------------------------------------------------------------*/
        /*-----------------------REMOVING CARDS SEGMENT-----------------------*/

        // Remove the first <cardsRemoved> cards from the deck
        void removeCards(int cardsRemoved);

        // Return deck card with <cardsRemoved> less card
        DeckCard operator-(int cardsRemoved);

        // Clear all cards from the deck
        void clearCards();
};

#endif