#ifndef SCORE_HPP
#define SCORE_HPP

#include "../Card/Card.hpp"
#include "../Combination/Combination.hpp"

class Score {
    public:
        // Konstruktor score
        Score() {}; 
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        virtual int value() = 0;
};

#endif