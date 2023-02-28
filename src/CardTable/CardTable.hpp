// File: CardTable.hpp
// Berisi deklarasi dari kelas CardTable

#ifndef CARDTABLE_HPP
#define CARDTABLE_HPP

#include "../InventoryHolder/InventoryHolder.hpp"

#include <iostream>
using namespace std;

class CardTable : public InventoryHolder {
public:
    // ctor
    CardTable();

    // user-defined ctor: copy the listOfCard to this object listOfCard
    CardTable(const vector<Card>& listOfCard);

    // dtor
    ~CardTable();

    // operator=
    CardTable& operator=(const CardTable& other);

    /*--------------------------------------------------------------------*/

    // Add 1 card from the top of DeckCard to the CardTable
    void addCards(const InventoryHolder& other);

    // Return table card with 1 more card (other)
    CardTable operator+(const Card& other);

    /*--------------------------------------------------------------------*/

    // Remove all cards from the table to start new game
    void removeCards(int cardsRemoved);

};

#endif