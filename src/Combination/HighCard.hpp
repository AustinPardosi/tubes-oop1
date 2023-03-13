#ifndef HIGHCARD_HPP
#define HIGHCARD_HPP

#include "Combination.hpp"

class HighCard : public Combination {
    public :
        HighCard(vector<Card>, vector<Card>);
        void check();
};

#endif