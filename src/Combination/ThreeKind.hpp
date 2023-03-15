// File: ThreeKind.hpp
// Berisi deklarasi dari kelas ThreeKind

#ifndef THREEKIND_HPP
#define THREEKIND_HPP

#include "Combination.hpp"

class ThreeKind : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        ThreeKind(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of three kind from the cards
        void check();
};

#endif