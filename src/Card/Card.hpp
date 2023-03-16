// File: Card.hpp
// Berisi deklarasi dari kelas Card

#ifndef CARD_H
#define CARD_H

#include "../Score/Score.hpp"

class Card : public Score {
    private:
        int cardColor;
        int cardNumber;

    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // default ctor
        Card();

        // user defined ctor
        Card(int, int);

        /*--------------------------------------------------------------------*/
        /*---------------------GETTER AND SETTER SEGMENT----------------------*/
        
        // set the card number
        void setCardNumber(int);

        // get the card number
        int getCardNumber() const;

        // set the card color
        void setCardColor(int);

        // get the card color
        int getCardColor() const;

        /*--------------------------------------------------------------------*/
        /*-------------------------CARD COLOR SEGMENT-------------------------*/
        
        // change color code of card into its corresponding word
        string convertColor (int) const;

        // print the card with its palette color
        void colorPalette();

        /*--------------------------------------------------------------------*/
        /*-------------------------CARD VALUE SEGMENT-------------------------*/
        
        // implement the value function
        double value() const;

        // check if this card is lesser than other
        bool operator< (const Card&);

        // check if this card is greater than other
        bool operator> (const Card&);

        // check if this card is the same as other
        bool operator== (const Card&);
};

#endif