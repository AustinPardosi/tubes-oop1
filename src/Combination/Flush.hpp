#include "Combination.hpp"

class Flush : public Combination {
    public :
        Flush(vector<Card>,vector<Card>);
        void check();
};