#ifndef FLUSH_HPP
#define FLUSH_HPP

#include "Combination.hpp"

class Flush : public Combination {
    public :
        Flush(vector<Card>,vector<Card>);
        void check();
};

#endif