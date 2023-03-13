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
        color = "Red";
    } else if (_cardColor == 2) {
        color = "Yellow";
    } else if (_cardColor == 1) {
        color = "Blue";
    } else if (_cardColor == 0) {
        color = "Green";
    }
    return color;
}

void Card::printInfoCard () const {
    string color = Card::convertColor (this->cardColor);
    if (color == "Red") {
        cout << "\033[1;31m" << this->cardNumber << " (" << color << ")" << "\033[0m" << endl;
    } else if (color == "Yellow") {
        cout << "\033[1;33m" << this->cardNumber << " (" << color << ")" << "\033[0m" << endl;
    } else if (color == "Blue") {
        cout << "\033[1;34m" << this->cardNumber << " (" << color << ")" << "\033[0m" << endl;
    } else if (color == "Green") {
        cout << "\033[1;32m" << this->cardNumber << " (" << color << ")" << "\033[0m" << endl;
    }
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
