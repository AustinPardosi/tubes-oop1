#ifndef FOURKIND_HPP
#define FOURKIND_HPP

#include "Combination.hpp"

class FourKind : public Combination {
    public :
        FourKind(vector<Card>, vector<Card>);
        void check();
};

#endif