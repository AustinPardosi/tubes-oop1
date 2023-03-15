// File: InventoryHolder.cpp
// Berisi implementasi dari kelas InventoryHolder

#include "InventoryHolder.hpp"

/*--------------------------------------------------------------------*/
/*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

InventoryHolder::InventoryHolder() {}

InventoryHolder::~InventoryHolder() {}

/*--------------------------------------------------------------------*/
/*---------------------ADDITIONAL METHOD SEGMENT----------------------*/

Card InventoryHolder::getCard(int index) const {
    return this->listOfCard[index];
}

void InventoryHolder::cardSetup(int nums) {
    this->cardLine[0] = "=============== ";
    this->cardLine[1] = "|             | ";
    if (nums < 10) {
        this->cardLine[2] = "| " + to_string(nums) + "           | ";
        this->cardLine[3] = "|           " + to_string(nums) + " | ";
    } else {
        this->cardLine[2] = "| " + to_string(nums) + "          | ";
        this->cardLine[3] = "|          " + to_string(nums) + " | ";
    }
}

void InventoryHolder::showCards() {
    int size = this->listOfCard.size();
    cardSetup(size);
    for (int i = 0; i < size; i++) {
        this->listOfCard[i].colorPalette();
        cout << this->cardLine[0];
        cout << "\033[0m";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        cardSetup(this->listOfCard[i].getCardNumber());
        this->listOfCard[i].colorPalette();
        cout << this->cardLine[2];
        cout << "\033[0m";
    }
    cout << endl;
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < size; i++) {
        this->listOfCard[i].colorPalette();
        cout << this->cardLine[1];
        cout << "\033[0m";
        }
        cout << endl;
    }
    for (int i = 0; i < size; i++) {
        cardSetup(this->listOfCard[i].getCardNumber());
        this->listOfCard[i].colorPalette();
        cout << this->cardLine[3];
        cout << "\033[0m";
    }
    cout << endl;
    for (int i = 0; i < size; i++) {
        this->listOfCard[i].colorPalette();
        cout << this->cardLine[0];
        cout << "\033[0m";
    }
    cout << endl;
}