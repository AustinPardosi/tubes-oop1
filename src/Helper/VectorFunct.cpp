#include "VectorFunct.hpp"

using namespace std;

// Fungsi cari maksimum, diasumsikan vector tidak kosong
template <class T>
T VectorFunct<T>::findMax(vector<T> vec) {
    T maximum = vec[0];
    for (int i=1; i<vec.size(); i++) {
        if (vec[i] > maximum) {
            maximum = vec[i];
        }
    }
    return maximum;
}

Combination* VectorFunct<Combination*>::findMax(vector<Combination*> vec) {
    Combination* maximum = vec[0];
    for (int i=1; i<vec.size(); i++) {
        if (*vec[i] > *maximum) {
            maximum = vec[i];
        }
    }
    return maximum;
}