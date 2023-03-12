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

void InventoryHolder::showCards() const {
    int i = 1;
    for_each(this->listOfCard.begin(), this->listOfCard.end(), [&j = i] (const Card& element) 
    {
        cout << "  " << j << ". ";
        element.printInfoCard();
        j++;
    });
}