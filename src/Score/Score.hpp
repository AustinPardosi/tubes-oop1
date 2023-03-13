#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
    public:
        // Konstruktor score
        Score() {}; 
        
        // Member Function
        // Menggunakan kartu yang dimiliki
        virtual float value() const = 0;
};

#endif