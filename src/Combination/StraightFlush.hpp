// File: StraightFlush.hpp
// Berisi deklarasi dari kelas StraightFlush

#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "Combination.hpp"

class StraightFlush : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        StraightFlush(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of straight flush from the cards
        void check();
};

#endif