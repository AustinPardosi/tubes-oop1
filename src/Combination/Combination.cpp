#include "Combination.hpp"

using namespace std;

Combination::Combination() {
    this->score = 0;
}

void Combination::setCard(vector<Card> playerCard, vector<Card> tableCard) {
    // Ambil kartu di tangan pemain
    for (int i=0; i<2; i++) {
        totalHand.push_back(playerCard[i]);
    }
    // Ambil kartu di table
    for (int i=0; i<5; i++) {
        totalHand.push_back(tableCard[i]);
    }
    sortHandByValue();
}

int Combination::value() {
    return this->score;
}

// Operator overloading
bool Combination::operator>(const Combination& other) {
    return this->score > other.score;
}

bool Combination::operator<(const Combination& other) {
    return this->score < other.score;
}

bool Combination::operator==(const Combination& other) {
    return this->score == other.score;
}

// Sorting
void Combination::sortHandByValue() {
    sort(totalHand.begin(),totalHand.end(), [](Card c1, Card c2) {
        return c1.getCardNumber() < c2.getCardNumber();
    });
}

void Combination::sortHandByColor() {
    sort(totalHand.begin(),totalHand.end(), [](Card c1, Card c2) {
        return c1.getCardColor() < c2.getCardColor();
    });
}