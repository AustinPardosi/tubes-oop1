// File: Combination.hpp
// Berisi deklarasi dari kelas Combination

#ifndef COMBINATION_HPP
#define COMBINATION_HPP

#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#include "../Card/Card.hpp"

class Combination : public Score {
    protected :
        double score;
        vector<Card> totalHand;

    public :
        /*--------------------------------------------------------------------*/
        /*------------------CREATION AND DESTRUCTION SEGMENT------------------*/
        
        // user defined ctor
        Combination(vector<Card>, vector<Card>);

        /*--------------------------------------------------------------------*/
        /*------------------------COMBO VALUE SEGMENT-------------------------*/
        
        // check the combination available, too abstract for this class
        virtual void check() = 0;
        
        // get the score of this combination
        double value() const;

        // check if this combo is greater than other combo
        bool operator>(const Combination&);

        // check if this combo is lesser than other combo
        bool operator<(const Combination&);

        // check if this combo is the same as other combo
        bool operator==(const Combination&);

        /*--------------------------------------------------------------------*/
        /*---------------------ADDITIONAL METHOD SEGMENT----------------------*/
        
        // sort card vector according to value;
        void sortHandByValue();
};

#endif