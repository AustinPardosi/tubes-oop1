#ifndef FULLHOUSE_HPP
#define FULLHOUSE_HPP

#include "Combination.hpp"

class FullHouse : public Combination {
    public :
        FullHouse(vector<Card>, vector<Card>);
        void check();
};

#endif