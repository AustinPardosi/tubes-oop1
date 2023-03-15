// File: TwoPair.hpp
// Berisi deklarasi dari kelas TwoPair

#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Combination.hpp"

class TwoPair : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        TwoPair(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of two pair from the cards
        void check();
};

#endif