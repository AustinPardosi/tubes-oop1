#include "Combination.hpp"

class HighCard : public Combination {
    public :
        HighCard(vector<Card>, vector<Card>);
        void check();
};