// File: FullHouse.hpp
// Berisi deklarasi dari kelas FullHouse

#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Combination.hpp"

class FullHouse : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // user defined ctor
        FullHouse(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of full house from the cards
        void check();
};

#endif