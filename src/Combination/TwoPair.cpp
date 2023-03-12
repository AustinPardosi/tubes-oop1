#include "TwoPair.hpp"

TwoPair::TwoPair(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

void TwoPair::check() {
    // Rumus : 2.78 + nomor kartu tertinggi/10 + nilai warna kartu tertinggi (0 untuk hijau/0.03 untuk biru/0.06 untuk kuning/0.09 untuk merah)
    // Nilai maksimum : 4.17
    int pairCount = 0;
    int firstPairIdx = -1;
    int i = 6;
    while (pairCount < 2 && i > 0) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber()) {
            pairCount++;
            if (pairCount == 1) {
                firstPairIdx = i;
            }
            i -= 2;
        } 
        else {
            i--;
        }
    }
    if (pairCount == 2) {
        score = 2.78 + totalHand[firstPairIdx].getCardNumber()/10;
        if (totalHand[firstPairIdx] > totalHand[firstPairIdx-1]) {
            score += totalHand[firstPairIdx].getCardColor() * 0.03;
        } else {
            score += totalHand[firstPairIdx-1].getCardColor() * 0.03;
        }
    }
}