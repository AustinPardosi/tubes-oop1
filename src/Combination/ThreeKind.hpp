#ifndef THREEKIND_HPP
#define THREEKIND_HPP

#include "Combination.hpp"

class ThreeKind : public Combination {
    public :
        ThreeKind(vector<Card>, vector<Card>);
        void check();
};

#endif