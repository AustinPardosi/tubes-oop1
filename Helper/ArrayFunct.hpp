#include "Card.hpp"

template <class T>
void swap(T* arr, int i, int j);
int partition(Card* arr, int i, int j, bool byValue);
void quickSortCards(Card* arr, int i, int j, bool byValue);