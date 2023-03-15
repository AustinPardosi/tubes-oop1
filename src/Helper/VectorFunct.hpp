#ifndef VECTORFUNCT_HPP
#define VECTORFUNCT_HPP

#include "../Combination/Combination.hpp"

// get the max value of a vector of T class
template <class T>
int getMax(vector<T>& vec) {
    int maxIdx = 0;
    for (int i=1; i<vec.size(); i++) {
        if (vec[i] > vec[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

#endif