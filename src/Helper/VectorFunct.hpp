#include <vector>
#include "../Combination/Combination.hpp"

using namespace std;

template <class T>
class VectorFunct {
    public :
        // Fungsi cari maksimum, diasumsikan vector tidak kosong
        static T findMax(vector<T>);
        static Combination* findMax(vector<Combination*>);
};