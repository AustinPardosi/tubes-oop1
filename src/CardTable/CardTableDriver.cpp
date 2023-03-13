// File: CardTableDriver.cpp
// Berisi driver dari kelas CardTable untuk keperluan testing
/* Compile command: 
   g++ -o testCardTable CardTableDriver.cpp CardTable.cpp "../InventoryHolder/InventoryHolder.cpp" "../Card/Card.cpp"
   ./testCardTable                                                                                                   */ 

// #include "CardTable.hpp"

/* int main() {
    vector<Card> list1;
    list1.push_back(Card(2, 8));
    list1.push_back(Card(3, 13));

    cout << "Show t1 after created using vector of card" << endl;
    CardTable t1(list1);
    t1.showCards();
    cout << endl;

    cout << "Show t2 after 1 card added from t1" << endl;
    CardTable t2;
    t2.addCards(t1);
    t2.showCards();
    cout << endl;

    cout << "Show t1 after cards removed from table" << endl;
    t1.removeCards(5);
    t1.showCards();

    return 0;
} */