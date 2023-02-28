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
bool Card::checkGreaterColor (int _cardColor) {
    return (this->cardColor > _cardColor);
}

bool Card::checkGreaterNumber (int _cardNumber) {
    return (this->cardNumber > _cardNumber);
}

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

// Operator
bool Card::operator< (const Card& c) {
    bool check = true;
    if(this->cardColor != c.cardColor) {
        if (Card::checkGreaterColor(c.cardColor)) {
            check = false;
        }
    } else if (this->cardColor == c.cardColor) {
        if (Card::checkGreaterNumber(c.cardNumber)) {
            check = false;
        }
    }
    return check;
}

bool Card::operator> (const Card& c) {
    bool check = true;
    if(this->cardColor != c.cardColor) {
        if (!Card::checkGreaterColor(c.cardColor)) {
            check = false;
        }
    } else if (this->cardColor == c.cardColor) {
        if (!Card::checkGreaterNumber(c.cardNumber)) {
            check = false;
        }
    }
    return check;
}

bool Card::operator== (const Card& c) {
    return (this->cardColor == c.cardColor) && (this->cardNumber == c.cardNumber);
}
