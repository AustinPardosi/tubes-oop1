#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include "../Card/Card.hpp"
#include "../Score/Score.hpp"
#include <vector>
#include <iostream>
#include <algorithm>

class Combination : public Score {
    private :
        float score;
        vector<Card> totalHand;
        const int NOT_FOUND_IDX = -1;
        // int highestCombo; // 0 : high card, 1 : pair, 2 : two pair, ..., 8 : straight flush

    public :
        Combination(vector<Card> playerCard, vector<Card> tableCard);
        float getScore();
        void setScore(float);
        void value();
        // Operator overloading
        bool operator>(const Combination&);
        bool operator<(const Combination&);
        bool operator==(const Combination&);
        // Sorting
        void sortHandByValue();
        void sortHandByColor();
        // Cek kombinasi dan ubah score
        void checkHighCard();
        int checkPair();
        int checkTwoPair();
        int checkThreeKind();
        int checkStraight();
        int checkFlush();
        void checkFullHouse();
        void checkFourKind();
        void checkStraightFlush();
        void calculateScore();
};

#endif