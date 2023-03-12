#include "Combination.hpp"

class FourKind : public Combination {
    public :
        FourKind(vector<Card>, vector<Card>);
        void check();
};