// File: DeckCard.cpp
// Berisi implementasi dari kelas DeckCard

#include "DeckCard.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

DeckCard::DeckCard() {}

DeckCard::DeckCard(const vector<Card>& listOfCard) {
    this->listOfCard = listOfCard;
}

DeckCard::~DeckCard() {}

DeckCard& DeckCard::operator=(const DeckCard& other) {
    this->listOfCard = other.listOfCard;
    return *this;
}

/*--------------------------------------------------------------------*/
/*------------------------ADDING CARDS SEGMENT------------------------*/

void DeckCard::addCards(const InventoryHolder& other) {
    vector<int> listNum;
    map<int, Card> Cards;
    for (int i = 1; i <= 52; i++) {
        listNum.push_back(i);
        Cards.insert(pair<int, Card> (i, Card(i%4, (i%13) + 1)));
    }

    mt19937::result_type seed = random_device()() ^ chrono::duration_cast<chrono::seconds>(
                                                    chrono::system_clock::now().time_since_epoch()).count();
    mt19937 gen(seed);
    shuffle(listNum.begin(), listNum.end(), gen);
    for_each(listNum.begin(), listNum.end(), [this, Cards] (int i){
        *this = *this + Cards.find(i)->second;
    });
}

DeckCard DeckCard::operator+(const Card& other) {
    vector<Card> temp = this->listOfCard;
    temp.push_back(other);
    return DeckCard(temp);
}

/*--------------------------------------------------------------------*/
/*-----------------------REMOVING CARDS SEGMENT-----------------------*/

void DeckCard::removeCards(int cardsRemoved) {
    *this = *this - cardsRemoved;
}

DeckCard DeckCard::operator-(int cardsRemoved) {
    vector<Card> temp = this->listOfCard;
    temp.erase(temp.begin(), temp.begin()+cardsRemoved);
    return DeckCard(temp);
}

void DeckCard::clearCards() {
    this->listOfCard.clear();
}