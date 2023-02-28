// File: DeckCardDriver.cpp
// Berisi driver dari kelas DeckCard untuk keperluan testing
/* Compile command: 
   g++ -o testDeckCard DeckCardDriver.cpp DeckCard.cpp "../InventoryHolder/InventoryHolder.cpp" "../Card/Card.cpp"
   ./testDeckCard                                                                                                 */

#include "DeckCard.hpp"

int main() {
    DeckCard d1, temp;
    d1.addCards(temp);

    cout << "All cards in deck are:" << endl;
    d1.showCards();

    cout << endl << "After pulling 2 cards, the cards in deck are:" << endl;
    d1.removeCards(2);
    d1.showCards();

    return 0;
}