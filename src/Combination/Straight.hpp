// File: Straight.hpp
// Berisi deklarasi dari kelas Straight

#ifndef STRAIGHT_HPP
#define STRAIGHT_HPP

#include "Combination.hpp"

class Straight : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        Straight(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of straight from the cards
        void check();
};

#endif