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

int main(int argc, char const *argv[]) {
    int sequenceSize;
    std::cin >> sequenceSize;
    std::vector<int> sequence;
    sequence.resize(sequenceSize);
    for (std::vector<int>::iterator itElem = sequence.begin(); itElem < sequence.end(); ++itElem) {
        std::cin >> *itElem;
    }
    SelectionSort(sequence.begin(), sequence.end());
    std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}