// File: StraightFlush.cpp
// Berisi implementasi dari kelas StraightFlush

#include "StraightFlush.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

StraightFlush::StraightFlush(vector<Card> playerCard, vector<Card> tableCard, int _checkParam) : Combination(playerCard,tableCard), checkParam(_checkParam) {}

/*--------------------------------------------------------------------*/
/*------------------------COMBO VALUE SEGMENT-------------------------*/

void StraightFlush::check() {
    // Rumus : 11.6 + Nomor kartu tertinggi /10 + kode warna
    // Nilai maksimum : 12.99
    bool foundStraightFlush = false;
    int i;
    switch(checkParam) {
        case(2) :
            i = 6;
            break;
        case(1) :
            i = 5;
            break;
        default :
            i = 4;
    }   
    while (!foundStraightFlush && i >= 4) {
        int j = i-1;
        int counter = 1;
        Card previous = totalHand[i];
        while (j >= 0 && previous.getCardNumber()-totalHand[j].getCardNumber() <= 1 && counter < 5) {
            if (previous.getCardColor() == totalHand[j].getCardColor()) {
                previous = totalHand[j];
                counter++;
            }
            j--;
        }
        if (counter >= 5) {
            foundStraightFlush= true;
        } else {
            i--;
        }
    }

    if (foundStraightFlush) {
        score = 11.6 + totalHand[i].getCardNumber()/10.0 + totalHand[i].getCardColor() * 0.03;
    }
}