// File: CardTable.cpp
// Berisi implementasi dari kelas CardTable

#include "CardTable.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

CardTable::CardTable() {}

CardTable::CardTable(const vector<Card>& listOfCard) {
    this->listOfCard = listOfCard;
}

CardTable::~CardTable() {}

CardTable& CardTable::operator=(const CardTable& other) {
    this->listOfCard = other.listOfCard;
    return *this;
}

/*--------------------------------------------------------------------*/
/*------------------------ADDING CARDS SEGMENT------------------------*/

void CardTable::addCards(const InventoryHolder& other) {
    *this = *this + other.getCard(0);
}

CardTable CardTable::operator+(const Card& card) {
    vector<Card> temp = this->listOfCard;
    temp.push_back(card);
    return CardTable(temp);
}

/*--------------------------------------------------------------------*/
/*-----------------------REMOVING CARDS SEGMENT-----------------------*/

void CardTable::removeCards(int cardsRemoved) {
    this->listOfCard.clear();
}