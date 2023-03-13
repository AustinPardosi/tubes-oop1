#ifndef TWOPAIR_HPP
#define TWOPAIR_HPP

#include "Combination.hpp"

class TwoPair : public Combination {
    public :
        TwoPair(vector<Card>, vector<Card>);
        void check();
};

#endif