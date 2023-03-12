#include "Combination.hpp"

class StraightFlush : public Combination {
    public :
        StraightFlush(vector<Card>, vector<Card>);
        void check();
};