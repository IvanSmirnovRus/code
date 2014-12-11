#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>


template<typename RandomAccessIterator>
void Insert(RandomAccessIterator begin, RandomAccessIterator current) {
    for (RandomAccessIterator it = current; it > begin; --it) {
        if (*(it - 1) > *it) {
            std::swap(*(it - 1), *it);
        }
    }
}
template<typename RandomAccessIterator>
void InsertionSort(RandomAccessIterator begin, RandomAccessIterator end) {
    for (RandomAccessIterator it = begin; it < end; ++it) {
        Insert(begin, it);
    }
}
