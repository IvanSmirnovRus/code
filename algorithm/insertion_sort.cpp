#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

// ------------------------------------------------------------------------------------------------
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

int main(int argc, char const *argv[]) {
    int sequenceSize;
    std::cin >> sequenceSize;
    std::vector<int> sequence;
    sequence.resize(sequenceSize);
    for (std::vector<int>::iterator itElem = sequence.begin(); itElem < sequence.end(); ++itElem) {
        std::cin >> *itElem;
    }
    InsertionSort(sequence.begin(), sequence.end());
    std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}