#include <iostream>
#include "Card.hpp"

// Konstruktor untuk menginisialisasi kartu
Card::Card() : Card(-1,-1)  {}

Card::Card(int _cardColor, int _cardNumber) {
    this->cardColor = _cardColor;
    this->cardNumber = _cardNumber;
}

// Cctor
Card::Card(const Card& c) {
    this->cardColor = c.cardColor;
    this->cardNumber = c.cardNumber;
}

// Getter, Setter
void Card::setCardNumber(int _cardNumber) {
    this->cardNumber = _cardNumber;
}

int Card::getCardNumber() const {
    return this->cardNumber;
}

void Card::setCardColor(int _cardColor) {
    this->cardColor = _cardColor;
}

int Card::getCardColor() const {
    return this->cardColor;
}

// Member Function
// Urutan Prioritas diconvert sebagai sebuah integer
// Urutan Prioritas = Merah(3) > Kuning(2) > Biru(1) > Hijau(0)

string Card::convertColor (int _cardColor) const {
    string color;
    if (_cardColor == 3) {
        color = "Merah";
    } else if (_cardColor == 2) {
        color = "Kuning";
    } else if (_cardColor == 1) {
        color = "Biru";
    } else if (_cardColor == 0) {
        color = "Hijau";
    }
    return color;
}

void Card::printInfoCard () const {
    string color = Card::convertColor (this->cardColor);
    cout << this->cardNumber << " (" << color << ")" << endl;
}

float Card::value() const {
    float val = (this->cardNumber/10) + (this->cardColor*0.03);
    return val;
}

// Operator
bool Card::operator< (const Card& c) {
    return value() < c.value();
}

bool Card::operator> (const Card& c) {
    return value() > c.value();
}

bool Card::operator== (const Card& c) {
    return value() == c.value();
}
