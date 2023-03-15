// File: Flush.hpp
// Berisi deklarasi dari kelas Flush

#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "Combination.hpp"

class Flush : public Combination {
    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/

        // user defined ctor
        Flush(vector<Card>,vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/

        // get the combination of flush from the cards
        void check();
};

#endif