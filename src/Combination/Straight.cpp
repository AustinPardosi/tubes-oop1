// File: Straight.cpp
// Berisi implementasi dari kelas Straight

#include "Straight.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Straight::Straight(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

/*--------------------------------------------------------------------*/
/*------------------------COMBO VALUE SEGMENT-------------------------*/

void Straight::check() {
    // Rumus : 5.56 + Nomor kartu terbesar/10 + Kode warna kartu bernomor terbesar
    // Nilai maksimum : 6.95
    bool foundStraight = false;
    int i = 6;
    while (!foundStraight && i >= 4) {
        int j = i-1;
        int previous = totalHand[i].getCardNumber();
        while (j >= i-4 && previous-totalHand[j].getCardNumber() <= 1) {
            previous = totalHand[j].getCardNumber();
            j--;
        }
        if (j < i-4) {
            foundStraight= true;
        } else {
            i--;
        }
    }

    if (foundStraight) {
        score = 5.56 + totalHand[i].getCardNumber()/10.0 + totalHand[i].getCardColor() * 0.03;
    }
}