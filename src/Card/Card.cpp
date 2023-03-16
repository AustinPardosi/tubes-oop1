// File: Card.cpp
// Berisi implementasi dari kelas Card

#include <iostream>
using namespace std;

#include "Card.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

Card::Card() : Card(-1,-1)  {}

Card::Card(int _cardColor, int _cardNumber) {
    this->cardColor = _cardColor;
    this->cardNumber = _cardNumber;
}

/*--------------------------------------------------------------------*/
/*---------------------GETTER AND SETTER SEGMENT----------------------*/

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

/*--------------------------------------------------------------------*/
/*-------------------------CARD COLOR SEGMENT-------------------------*/

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

void Card::colorPalette() {
    string color = Card::convertColor (this->cardColor);
    // determining colors
    if (color == "Red") {
        cout << "\033[1;31m";
    } else if (color == "Yellow") {
        cout << "\033[1;33m";
    } else if (color == "Blue") {
        cout << "\033[1;34m";
    } else if (color == "Green") {
        cout << "\033[1;32m";
    }
}

/*--------------------------------------------------------------------*/
/*-------------------------CARD VALUE SEGMENT-------------------------*/

double Card::value() const {
    float val = (this->cardNumber/10) + (this->cardColor*0.03);
    return val;
}

bool Card::operator< (const Card& c) {
    return value() < c.value();
}

bool Card::operator> (const Card& c) {
    return value() > c.value();
}

bool Card::operator== (const Card& c) {
    return value() == c.value();
}