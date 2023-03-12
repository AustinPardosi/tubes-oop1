#include "FullHouse.hpp"

FullHouse::FullHouse(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

void FullHouse::check() {
    // Rumus : 9 + (Nomor kartu yang ada 3)/10
    // Nilai maksimum : 10.3
    bool foundThree = false;
    int i=6;
    bool foundTwo = false;
    while (!foundThree && i>=2) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber() && totalHand[i-1].getCardNumber() == totalHand[i-2].getCardNumber()) {
            foundThree == true;
        } else {
            i--;
        }
    }
    if (foundThree) {
        int j=6;
        while (!foundTwo && j >= 1) {
            if ((j > i || j < i-2) && (j-1 > i || j-1 < i-2)) {
                if (totalHand[j].getCardNumber() == totalHand[j-1].getCardNumber()) {
                    foundTwo = true;
                } else {
                    j--;
                }
            } else {
                j--;
            }
        }
    }
    if (foundThree && foundTwo) {
        score = 9 + totalHand[i].getCardNumber()/10;
    }
}