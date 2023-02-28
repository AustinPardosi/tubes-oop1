#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
public:
	// Konstruktor untuk menginisialisasi kartu
	Card(int, int);

    // Cctor 
    Card(const Card&);

	// Getter, Setter
	void setCardNumber(int);
	int getCardNumber() const;
	void setCardColor(int);
	int getCardColor() const;

    //  Member Function
    bool checkGreaterColor (int);
    bool checkGreaterNumber (int);
    string convertColor (int) const;
    void printInfoCard () const;

    // Operator 
    bool operator< (const Card&);
    bool operator> (const Card&);
    bool operator== (const Card&);

private:
    int cardColor;
    int cardNumber;
};

#endif