#ifndef VECTORFUNCT_HPP
#define VECTORFUNCT_HPP

#include <vector>
#include "../Combination/Combination.hpp"

using namespace std;

template <class T>
class VectorFunct {
    public :
        // Fungsi cari maksimum, diasumsikan vector tidak kosong
        static int findMax(vector<T>);
        static int findMax(vector<Combination*>);
};

#endif