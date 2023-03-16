// File: Score.hpp
// Berisi deklarasi dari dari kelas abstrak Score

#ifndef SCORE_HPP
#define SCORE_HPP

class Score {
    public:
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // ctor
        Score() {}; 
        
        /*--------------------------------------------------------------------*/
        /*---------------------------VALUE SEGMENT----------------------------*/
        
        // abstract method to get a value, too abstract to implement
        virtual double value() const = 0;
};

#endif