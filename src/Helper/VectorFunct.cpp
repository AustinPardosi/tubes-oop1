#include "VectorFunct.hpp"

using namespace std;

// Fungsi cari indeks maksimum, diasumsikan vector tidak kosong
template <class T>
int VectorFunct<T>::findMax(vector<T> vec) {
    int maxIdx = 0;
    for (int i=1; i<vec.size(); i++) {
        if (vec[i] > vec[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}

int VectorFunct<Combination*>::findMax(vector<Combination*> vec) {
    int maxIdx = 0;
    for (int i=1; i<vec.size(); i++) {
        if (*vec[i] > *vec[maxIdx]) {
            maxIdx = i;
        }
    }
    return maxIdx;
}