// File: Flush.cpp
// Berisi implementasi dari kelas Flush

#include "Flush.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Flush::Flush(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

/*--------------------------------------------------------------------*/
/*------------------------COMBO VALUE SEGMENT-------------------------*/

void Flush::check() {
    // Rumus : 7 + Nomor kartu terbesar/10 + Nomor kartu terbesar kedua/1000 + Nomor kartu ketiga terbesar / 100000 dst.
    // Nilai maksimum : 8.3121110906
    // Hitung jumlah kemunculan setiap warna
    int colorCount[] = {0,0,0,0};
    for (int i=0; i<7; i++) {
        colorCount[totalHand[i].getCardColor()]++;
    }
    int i = 3;
    while (i >= 0 && colorCount[i] < 5) {
        i--;
    }
    if (i >= 0) {
        // Ada warna yang jumlah kemunculannya 5
        int j = 6;
        int counter = 0;
        score = 7.0;
        while (counter < 5) {
            if (totalHand[j].getCardColor() == i) {
                score += totalHand[j].getCardNumber()/(10.0 * pow(100,counter));
            }
            j--;
            counter++;
        }
        score += i*3/(10.0 * pow(100,counter+1));
    }
}