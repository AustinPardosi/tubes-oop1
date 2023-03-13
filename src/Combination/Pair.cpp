#include "Pair.hpp"

Pair::Pair(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

void Pair::check() {
    // Rumus : 1.39 + nomor kartu*0.1 + kode warna tertinggi (0 untuk hijau/0.03 untuk biru/0.06 untuk kuning/0.09 untuk merah)
    // Nilai maksimum : 2.78
    bool foundPair = false;
    int i = 6;
    while (!foundPair && i > 0) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber()) {
            foundPair = true;
        } else {
            i--;
        }
    }
    if (foundPair) {
        score = 1.39 + totalHand[i].getCardNumber()/10.0;
        if (totalHand[i] > totalHand[i-1]) {
            score += totalHand[i].getCardColor() * 0.03;
        } else {
            score += totalHand[i-1].getCardColor() * 0.03;
        }
    }
}