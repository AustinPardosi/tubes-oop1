#include "Combination.hpp"
#include "../Helper/ArrayFunct.hpp"

Combination::Combination(Card* playerCard, Card* tableCard) {
    this->score = 0;
    this->totalHand = new Card[7];
    // Ambil kartu di tangan pemain
    for (int i=0; i<2; i++) {
        totalHand[i].setCardColor(playerCard[i].getCardColor());
        totalHand[i].setCardNumber(playerCard[i].getCardNumber());
    }
    // Ambil kartu di table
    for (int i=0; i<5; i++) {
        totalHand[i+2].setCardColor(tableCard[i].getCardColor());
        totalHand[i+2].setCardNumber(tableCard[i].getCardNumber());
    }
}

Combination::~Combination() {
    delete[] this->totalHand;
}

float Combination::getScore() {
    return this->score;
}

void Combination::setScore(float s) {
    this->score = s;
}

// Operator overloading
bool Combination::operator>(const Combination& other) {
    return this->score > other.score;
}
bool Combination::operator<(const Combination& other) {
    return this->score < other.score;
}
bool Combination::operator==(const Combination& other) {
    return this->score == other.score;
}

// Sorting
void Combination::sortHandByValue() {
    quickSortCards(this->totalHand,0,6,true);
}
void Combination::sortHandByColor() {
    quickSortCards(this->totalHand,0,6,false);
}

// Cek kombinasi dan ubah score
void Combination::checkHighCard() {
    // Rumus : nomor kartu/10 + nilai warna kartu (0 untuk hijau/0.03 untuk biru/0.06 untuk kuning/0.09 untuk merah)
    // Nilai maksimum : 1.39
    score = totalHand[6].getCardNumber()/10;
    score += totalHand[6].getCardColor() * 0.03;
}
void Combination::checkPair() {
    // Rumus : 1.39 + nomor kartu/10 + kode warna tertinggi (0 untuk hijau/0.03 untuk biru/0.06 untuk kuning/0.09 untuk merah)
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
        score = 1.39 + totalHand[i].getCardNumber()/10;
        if (totalHand[i] > totalHand[i-1]) {
            score += totalHand[i].getCardColor() * 0.03;
        } else {
            score += totalHand[i-1].getCardColor() * 0.03;
        }
    }
}
void Combination::checkTwoPair() {
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
void Combination::checkThreeKind() {
    // Rumus : 4.17 + Nomor kartu/10 + Warna tertinggi
    // Nilai maksimum : 5.56
    bool foundThreeKind = false;
    int i = 6;
    while (!foundThreeKind && i > 1) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber() && totalHand[i-1].getCardNumber() == totalHand[i-2].getCardNumber()) {
            foundThreeKind = true;
        } else {
            i--;
        }
    }
    if (foundThreeKind) {
        score = 1.39 + totalHand[i].getCardNumber()/10;
        if (totalHand[i] > totalHand[i-1]) {
            score += totalHand[i].getCardColor() * 0.03;
        } else {
            score += totalHand[i-1].getCardColor() * 0.03;
        }
    }
}
void Combination::checkStraight() {
    // Rumus : 5.56 + Nomor kartu terbesar/10 + Warna tertinggi
    // Nilai maksimum : 6.95
}
void Combination::checkFlush() {
    // Rumus : 6.95 + Nomor kartu terbesar/10 + Warna
    // Nilai maksimum : 8.34
}
void Combination::checkFullHouse() {
    // Rumus : 8.34 + Nomor kartu yang ada 3/10
    // Nilai maksimum : 9.64
}
void Combination::checkFourKind() {
    // Rumus : 9.64 + Nomor kartu /10
    // Nilai maksimum : 10.94
}
void Combination::checkStraightFlush() {
    // Rumus : 10.94 + Nomor kartu tertinggi /10 + kode warna
    // Nilai maksimum : 12.33
}

void Combination::calculateScore() {
    sortHandByValue();
    checkPair();
    checkTwoPair();
    checkThreeKind();
    checkStraight();
    checkFlush();
    checkFullHouse();
    checkFourKind();
    checkStraightFlush();
}