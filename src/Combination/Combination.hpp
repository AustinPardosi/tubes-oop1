#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include "../Card/Card.hpp"
#include "../Score/Score.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

class Combination : public Score {
    protected :
        float score;
        vector<Card> totalHand;
        // int highestCombo; // 0 : high card, 1 : pair, 2 : two pair, ..., 8 : straight flush

    public :
        Combination(vector<Card>, vector<Card>);
        int value();
        // Operator overloading
        bool operator>(const Combination&);
        bool operator<(const Combination&);
        bool operator==(const Combination&);
        // Sorting
        void sortHandByValue();
        void sortHandByColor();
        // Cek kombinasi dan ubah score
        virtual void check()=0;
};

#endif