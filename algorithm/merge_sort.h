#include <iostream>
#include <algorithm>
#include <vector>


template<typename RandomAccessIterator>
void InplaceMerge(RandomAccessIterator beginFirst, RandomAccessIterator endFirst,
           RandomAccessIterator beginSecond, RandomAccessIterator endSecond) {
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> storage(beginFirst, endFirst);
    RandomAccessIterator storageIt = storage.begin();
    while (storageIt != storage.end() && beginSecond != endSecond) {
        *beginFirst++ = (*storageIt > *beginSecond) ? *beginSecond++ : *storageIt++; 
    }
    if (storageIt == storage.end()) {
        std::copy(beginSecond, endSecond, beginFirst);
        return;
    }
    if (beginSecond == endSecond) {
        std::copy(storageIt, storage.end(), beginFirst);
        return;
    }
}

template<typename RandomAccessIterator>
void MergeSort(RandomAccessIterator begin, RandomAccessIterator end) {
    for (size_t blockSize = 1; blockSize < std::distance(begin, end); blockSize *= 2) {
        for (RandomAccessIterator it = begin; it + blockSize < end; it += 2 * blockSize) {
            RandomAccessIterator endBlock;
            endBlock = (std::distance(it, end) < 2 * blockSize) ? end : it + 2 * blockSize;
            InplaceMerge(it, it + blockSize, it + blockSize, endBlock);
        }
    }
}
