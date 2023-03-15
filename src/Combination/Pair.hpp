// File: Pair.hpp
// Berisi deklarasi dari kelas Pair

#ifndef PAIR_HPP
#define PAIR_HPP

#include "Combination.hpp"

class Pair : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        Pair(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of pair from the cards
        void check();
};

#endif