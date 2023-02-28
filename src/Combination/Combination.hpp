#include "../Card/Card.hpp"

class Combination {
    private :
        float score;
        Card* totalHand;
        // int highestCombo; // 0 : high card, 1 : pair, 2 : two pair, ..., 8 : straight flush

    public :
        Combination(Card* playerCard, Card* tableCard);
        ~Combination();
        float getScore();
        void setScore(float);
        // Operator overloading
        bool operator>(const Combination&);
        bool operator<(const Combination&);
        bool operator==(const Combination&);
        // Sorting
        void sortHandByValue();
        void sortHandByColor();
        // Cek kombinasi dan ubah score
        void checkHighCard();
        void checkPair();
        void checkTwoPair();
        void checkThreeKind();
        void checkStraight();
        void checkFlush();
        void checkFullHouse();
        void checkFourKind();
        void checkStraightFlush();
        void calculateScore();
};