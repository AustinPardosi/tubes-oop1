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
    for (int i = 1; i <= 52; i++) {
        listNum.push_back(i);
    }
    mt19937::result_type seed = random_device()() ^ chrono::duration_cast<chrono::seconds>(
                                                    chrono::system_clock::now().time_since_epoch()).count();
    mt19937 gen(seed);

    while (!listNum.empty()) {
        uniform_int_distribution<> distr(0, listNum.size()-1);
        int index = distr(gen);
        *this = *this + Card(listNum[index]%4, (listNum[index]%13) + 1);
        listNum.erase(listNum.begin() + index);
    }
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