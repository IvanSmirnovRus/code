#include <iostream>
#include <algorithm>
#include <vector>
// ------------------------------------------------------------------------------------------------

template<typename RandomAccessIterator>
void Merge(RandomAccessIterator beginFirst, RandomAccessIterator endFirst,
           RandomAccessIterator beginSecond, RandomAccessIterator endSecond) {
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> storage(beginFirst, endFirst);
    RandomAccessIterator storageIt = storage.begin();
    while (true) {
        if (storageIt == storage.end()) {
            std::copy(beginSecond, endSecond, beginFirst);
            return;
        }
        if (beginSecond == endSecond) {
            std::copy(storageIt, storage.end(), beginFirst);
            return;
        }
        *beginFirst++ = (*storageIt > *beginSecond) ? *beginSecond++ : *storageIt++; 
    }
}

template<typename RandomAccessIterator>
void MergeSort(RandomAccessIterator begin, RandomAccessIterator end) {
    for (size_t blockSize = 1; blockSize < std::distance(begin, end); blockSize *= 2) {
        for (RandomAccessIterator it = begin; it + blockSize < end; it += 2 * blockSize) {
            RandomAccessIterator endBlock;
            endBlock = (std::distance(it, end) < 2 * blockSize) ? end : it + 2 * blockSize;
            Merge(it, it + blockSize, it + blockSize, endBlock);
        }
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
    MergeSort(sequence.begin(), sequence.end());
    std::copy(sequence.begin(), sequence.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}