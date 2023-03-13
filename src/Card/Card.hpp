#ifndef CARD_H
#define CARD_H

#include <string>
#include "../Score/Score.hpp"

using namespace std;

class Card : public Score {
public:
	// Konstruktor untuk menginisialisasi kartu
    Card();
	Card(int, int);

    // Cctor 
    Card(const Card&);

	// Getter, Setter
	void setCardNumber(int);
	int getCardNumber() const;
	void setCardColor(int);
	int getCardColor() const;

    //  Member Function
    string convertColor (int) const;
    void printInfoCard () const;
    float value() const;

    // Operator 
    bool operator< (const Card&);
    bool operator> (const Card&);
    bool operator== (const Card&);

private:
    int cardColor;
    int cardNumber;
};

#endif