#ifndef STRAIGHTFLUSH_HPP
#define STRAIGHTFLUSH_HPP

#include "Combination.hpp"

class StraightFlush : public Combination {
    public :
        StraightFlush(vector<Card>, vector<Card>);
        void check();
};

#endif