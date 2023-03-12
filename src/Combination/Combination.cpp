#include "Combination.hpp"

using namespace std;

Combination::Combination() {
    this->score = 0;
}

void Combination::setCard(vector<Card> playerCard, vector<Card> tableCard) {
    // Ambil kartu di tangan pemain
    for (int i=0; i<2; i++) {
        totalHand.push_back(playerCard[i]);
    }
    // Ambil kartu di table
    for (int i=0; i<5; i++) {
        totalHand.push_back(tableCard[i]);
    }
}

int Combination::value() {
    return this->score;
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
    std::sort(totalHand.begin(),totalHand.end(), [](Card c1, Card c2)
                {
                    return c1.getCardNumber() < c2.getCardNumber();
                }
            );
}
void Combination::sortHandByColor() {
    std::sort(totalHand.begin(),totalHand.end(), [](Card c1, Card c2)
                {
                    return c1.getCardColor() < c2.getCardColor();
                }
            );
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
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber() && 
            totalHand[i-1].getCardNumber() == totalHand[i-2].getCardNumber()) 
        {
            foundThreeKind = true;
        } else {
            i--;
        }
    }
    if (foundThreeKind) {
        score = 4.17 + totalHand[i].getCardNumber()/10;
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
void Combination::checkStraight() {
    // Rumus : 5.56 + Nomor kartu terbesar/10 + Kode warna kartu bernomor terbesar
    // Nilai maksimum : 6.95
    bool foundStraight = false;
    int i = 6;
    while (!foundStraight && i >= 4) {
        int j = i-1;
        int previous = totalHand[i].getCardNumber();
        while (j >= i-4 && previous-totalHand[j].getCardNumber() == 1) {
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
        score = 5.56 + totalHand[i].getCardNumber()/10 + totalHand[i].getCardColor() * 0.03;
    }
}
void Combination::checkFlush() {
    // Rumus : 7 + Nomor kartu terbesar/10 + Nomor kartu terbesar kedua/1000 + Nomor kartu ketiga terbesar / 100000 dst.
    // Nilai maksimum : 8.313131312
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
        score = 7;
        while (counter < 5) {
            if (totalHand[j].getCardColor() == i) {
                score += totalHand[j].getCardNumber()/(10 * pow(100,counter));
            }
            j--;
        }
    }
}
void Combination::checkFullHouse() {
    // Rumus : 9 + (Nomor kartu yang ada 3)/10
    // Nilai maksimum : 10.3
    bool foundThree = false;
    int i=6;
    bool foundTwo = false;
    while (!foundThree && i>=2) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber() && totalHand[i-1].getCardNumber() == totalHand[i-2].getCardNumber()) {
            foundThree == true;
        } else {
            i--;
        }
    }
    if (foundThree) {
        int j=6;
        while (!foundTwo && j >= 1) {
            if ((j > i || j < i-2) && (j-1 > i || j-1 < i-2)) {
                if (totalHand[j].getCardNumber() == totalHand[j-1].getCardNumber()) {
                    foundTwo = true;
                } else {
                    j--;
                }
            } else {
                j--;
            }
        }
    }
    if (foundThree && foundTwo) {
        score = 9 + totalHand[i].getCardNumber()/10;
    }
}
void Combination::checkFourKind() {
    // Rumus : 10.3 + Nomor kartu /10
    // Nilai maksimum : 11.6
    int i=6;
    bool foundFour = false;
    while (!foundFour && i >=3) {
        if (totalHand[i].getCardNumber() == totalHand[i-1].getCardNumber() && 
            totalHand[i-1].getCardNumber() == totalHand[i-2].getCardNumber() &&
            totalHand[i-2].getCardNumber() == totalHand[i-3].getCardNumber()) {
                foundFour = true;
        } else {
            i--;
        }
    }
    if (foundFour) {
        score = 10.3 + totalHand[i].getCardNumber()/10;
    }
}
void Combination::checkStraightFlush() {
    // Rumus : 11.6 + Nomor kartu tertinggi /10 + kode warna
    // Nilai maksimum : 12.99
    bool foundStraightFlush = false;
    int i = 6;
    while (!foundStraightFlush && i >= 4) {
        int j = i-1;
        Card previous = totalHand[i];
        while (j >= i-4 && previous.getCardNumber()-totalHand[j].getCardNumber() == 1 && previous.getCardColor() == totalHand[j].getCardColor()) {
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
        score = 11.6 + totalHand[i].getCardNumber()/10 + totalHand[i].getCardColor() * 0.03;
    }
}

void Combination::calculateScore(int untilWhichParam) {
    // calculateScore untuk tiebreaker, dibatasi sampe kombinasi mana yang dicek
    /*
        9 : sampe straightflush
        8 : sampe four of a kind
        7 : sampe full house
        6 : sampe flush
        5 : sampe straight
        4 : sampe three of a kind
        3 : sampe two pair
        2 : sampe pair
        1 : sampe high card
    */
    sortHandByValue();
    checkHighCard();
    if (untilWhichParam >= 2) {
        checkPair();
    }
    if (untilWhichParam >= 3) {
        checkTwoPair();
    }
    if (untilWhichParam >= 4) {
        checkThreeKind();
    }
    if (untilWhichParam >= 5) {
        checkStraight();
    }
    if (untilWhichParam >= 6) {
        checkFlush();
    }
    if (untilWhichParam >= 7) {
        checkFullHouse();
    }
    if (untilWhichParam >= 8) {
        checkFourKind();
    }
    if (untilWhichParam >= 9) {
        checkStraightFlush();
    }
}