#ifndef PAIR_HPP
#define PAIR_HPP

#include "Combination.hpp"

class Pair : public Combination {
    public :
        Pair(vector<Card>, vector<Card>);
        void check();
};

#endif