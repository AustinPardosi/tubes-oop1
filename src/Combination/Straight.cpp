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
        int counter = 1;
        int j = i-1;
        int previous = totalHand[i].getCardNumber();
        while (j >= 0 && previous-totalHand[j].getCardNumber() <= 1 && counter < 5) {
            if (previous-totalHand[j].getCardNumber() == 1) {
                previous = totalHand[j].getCardNumber();
                counter++;
            } else if (totalHand[j] > totalHand[j+1]) {
                Card temp = totalHand[j+1];
                totalHand[j+1] = totalHand[j];
                totalHand[j] = temp;
            }
            j--;
        }
        if (counter >= 5) {
            foundStraight= true;
        } else {
            i--;
        }
    }

    if (foundStraight) {
        score = 5.56 + totalHand[i].getCardNumber()/10.0 + totalHand[i].getCardColor() * 0.03;
    }
}