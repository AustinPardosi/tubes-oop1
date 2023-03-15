// File: FourKind.hpp
// Berisi deklarasi dari kelas FourKind

#ifndef FOURKIND_HPP
#define FOURKIND_HPP

#include "Combination.hpp"

class FourKind : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        FourKind(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of four kind from the cards
        void check();
};

#endif