#include "ArrayFunct.hpp"

template <class T>
void swap(T* arr, int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(Card* arr, int i, int j, bool byValue) {
    int pivotIdx = (i+j)/2;
    int p = i-1;
    int q = j+1;
    int pivot;

    if (byValue) {
        pivot = arr[pivotIdx].getCardNumber();
    } else {
        pivot = arr[pivotIdx].getCardColor();
    }

    do {
        if (byValue) {
            do {
                p += 1;
            } while (arr[p].getCardNumber() < pivot);
            do {
                q -= 1;
            } while (arr[q].getCardNumber() > pivot);
        } else {
            do {
                p += 1;
            } while (arr[p].getCardColor() < pivot);
            do {
                q -= 1;
            } while (arr[q].getCardColor() > pivot);
        }
        swap(arr,p,q);
    } while (p < q);

    swap(arr,p,q);
    swap(arr,i,q);
    return q;
}

void quickSortCards(Card* arr, int i, int j, bool byValue) {
    if (i < j) {
        int pos = partition(arr, i, j, byValue);
        quickSortCards(arr, i, pos-1, byValue);
        quickSortCards(arr, pos+1, j, byValue);
    }
}