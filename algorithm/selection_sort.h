#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>


template<typename RandomAccessIterator>
size_t GetIndexMinimum(RandomAccessIterator begin, RandomAccessIterator end) {
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T minimum = *begin;
    size_t indexMinimum = 0;
    for (RandomAccessIterator it = begin + 1; it < end; ++it) {
        if (*it < minimum) {
            minimum = *it;
            indexMinimum = it - begin;
        }
    }
    return indexMinimum;
}

template<typename RandomAccessIterator>
void SelectionSort(RandomAccessIterator begin, RandomAccessIterator end) {
    for (RandomAccessIterator it = begin; it < end; ++it) {
        size_t indexMinimum = GetIndexMinimum(it, end);
        std::swap(*it, *(it + indexMinimum));
    } 
}
