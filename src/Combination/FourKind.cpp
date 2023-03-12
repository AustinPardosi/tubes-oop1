#include "FourKind.hpp"

void FourKind::check() {
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