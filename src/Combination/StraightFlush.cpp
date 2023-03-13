#include "StraightFlush.hpp"

StraightFlush::StraightFlush(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

void StraightFlush::check() {
    // Rumus : 11.6 + Nomor kartu tertinggi /10 + kode warna
    // Nilai maksimum : 12.99
    bool foundStraightFlush = false;
    int i = 6;
    while (!foundStraightFlush && i >= 4) {
        int j = i-1;
        Card previous = totalHand[i];
        while (j >= i-4 && previous.getCardNumber()-totalHand[j].getCardNumber() <= 1 && 
                previous.getCardColor() == totalHand[j].getCardColor()) {
            previous = totalHand[j];
            j--;
        }
        if (j < i-4) {
            foundStraightFlush= true;
        } else {
            i--;
        }
    }

    if (foundStraightFlush) {
        score = 11.6 + totalHand[i].getCardNumber()/10.0 + totalHand[i].getCardColor() * 0.03;
    }
}