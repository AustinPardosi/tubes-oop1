#ifndef VECTORFUNCT_HPP
#define VECTORFUNCT_HPP

#include <vector>
#include "../Combination/Combination.hpp"

using namespace std;

// Fungsi cari maksimum, diasumsikan vector tidak kosong
template <class T>
int getMax(vector<T> vec) {
    int maxIdx = 0;
    for (int i=1; i<vec.size(); i++) {
        if (vec[i] > vec[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

#endif