// File: HighCard.cpp
// Berisi implementasi dari kelas HighCard

#include "HighCard.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

HighCard::HighCard(vector<Card> playerCard, vector<Card> tableCard) : Combination(playerCard,tableCard) {}

/*--------------------------------------------------------------------*/
/*------------------------COMBO VALUE SEGMENT-------------------------*/

void HighCard::check() {
    // Rumus : nomor kartu/10 + nilai warna kartu (0 untuk hijau/0.03 untuk biru/0.06 untuk kuning/0.09 untuk merah)
    // Nilai maksimum : 1.39
    score = totalHand[6].getCardNumber()/10.0;
    score += totalHand[6].getCardColor() * 0.03;
}