// File: HighCard.hpp
// Berisi deklarasi dari kelas HighCard

#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "Combination.hpp"

class HighCard : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        HighCard(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of high card from the cards
        void check();
};

#endif