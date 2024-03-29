// File: ThreeKind.cpp
// Berisi implementasi dari kelas ThreeKind

#include "ThreeKind.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

ThreeKind::ThreeKind(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

/*--------------------------------------------------------------------*/
/*------------------------COMBO VALUE SEGMENT-------------------------*/

void ThreeKind::check() {
    // Rumus : 4.17 + Nomor kartu/10 + Warna tertinggi
    // Nilai maksimum : 5.56
    bool foundThreeKind = false;
    int i = 6;
    while (!foundThreeKind && i > 1) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber() && 
            totalHand[i-1].getCardNumber() == totalHand[i-2].getCardNumber()) 
        {
            foundThreeKind = true;
        } else {
            i--;
        }
    }
    if (foundThreeKind) {
        score = 4.17 + totalHand[i].getCardNumber()/10.0;
        if (totalHand[i] > totalHand[i-1]) {
            if (totalHand[i] > totalHand[i-2]) {
                score += totalHand[i].getCardColor() * 0.03;
            } else {
                score += totalHand[i-2].getCardColor() * 0.03;
            }
        } else {
            if (totalHand[i-1] > totalHand[i-2]) {
                score += totalHand[i-1].getCardColor() * 0.03;
            } else {
                score += totalHand[i-2].getCardColor() * 0.03;
            }
        }
    }
}