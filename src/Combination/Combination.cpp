#include "Combination.hpp"

using namespace std;

Combination::Combination(vector<Card> playerCard, vector<Card> tableCard) {
    this->score = 0;
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

float Combination::value() const {
    return this->score;
}

// Operator overloading
bool Combination::operator>(const Combination& other) {
    return this->value() > other.value();
}

bool Combination::operator<(const Combination& other) {
    return this->value() < other.value();
}

bool Combination::operator==(const Combination& other) {
    return this->value() == other.value();
}

// Sorting
void Combination::sortHandByValue() {
    sort(totalHand.begin(),totalHand.end(), [](Card c1, Card c2) {
        return c1.getCardNumber() < c2.getCardNumber();
    });
}