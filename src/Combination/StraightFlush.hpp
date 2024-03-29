// File: StraightFlush.hpp
// Berisi deklarasi dari kelas StraightFlush

#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "Combination.hpp"

class StraightFlush : public Combination {
    private :
        int checkParam;
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        StraightFlush(vector<Card>, vector<Card>, int);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of straight flush from the cards
        void check();
};

#endif