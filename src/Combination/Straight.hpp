#include "Combination.hpp"

class Straight : public Combination {
    public :
        Straight(vector<Card>, vector<Card>);
        void check();
};