#include "Card.cpp"

int main() {
    Card c1(3, 10);
    Card c2(2, 7);
    Card c3(c2);

    int x1, x2, x3, y1, y2, y3;

    x1 = c1.getCardColor();
    y1 = c1.getCardNumber();
    x2 = c2.getCardColor();
    y2 = c2.getCardNumber();
    x3 = c3.getCardColor();
    y3 = c3.getCardNumber();

    cout << x1 << " " << y1 << endl;
    cout << x2 << " " << y2 << endl;
    cout << x3 << " " << y3 << endl;

    c3.setCardColor(1);
    c3.setCardNumber(1);
    cout << c3.getCardColor() << " " << c3.getCardNumber() << endl;

    if (c1.checkGreaterColor(2)) {
        cout << "YES" << endl;
    } 
    if (!c1.checkGreaterNumber(11)) {
        cout << "NO" << endl;
    }

    c1.printInfoCard();
    c2.printInfoCard();
    c3.printInfoCard();

    if (c1 < c2) {
        cout << "c1 < c2" << endl;
    } else {
        cout << "c1 > c2" << endl;
    }
    return 0;
}