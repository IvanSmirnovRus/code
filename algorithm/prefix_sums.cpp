#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>

// ------------------------------------------------------------------------------------------------

template<typename RandomAccessIterator>
int CountSegment(RandomAccessIterator begin, RandomAccessIterator end, 
                 long long int leftBound, long long int rightBound) {
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    int sum = 0;
    for (RandomAccessIterator it = begin; it < end; ++it) {
        if (*it >= leftBound && *it <= rightBound) {
            ++sum;
        }
    }
    for (int blockSize = 1; blockSize < std::distance(begin, end); blockSize *= 2) {
        for (RandomAccessIterator it = begin; it + blockSize < end; it += 2 * blockSize) {
            RandomAccessIterator endBlock;
            endBlock = (std::distance(it, end) < 2 * blockSize) ? end : it + 2 * blockSize;
            RandomAccessIterator lIt = it;
            RandomAccessIterator rIt = it + blockSize;
            for (; rIt < endBlock && lIt < it + blockSize;) {
                if ((*rIt - *lIt) <= rightBound) {
                    if ((*rIt - *lIt) >= leftBound) {
                        sum += std::distance(rIt,
                        std::upper_bound(rIt, endBlock, *lIt + rightBound));
                        ++lIt;
                    } else {
                        ++rIt;
                    }
                } else {
                    ++lIt;
                }
            }
            std::vector<T> output(it, it + blockSize);
            std::merge(output.begin(), output.end(), it + blockSize, endBlock, it);
        }
    }
    return sum;
}



int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    size_t sequenceSize;
    std::cin >> sequenceSize;
    std::vector<int> sequence;
    sequence.resize(sequenceSize);
    for (std::vector<int>::iterator it = sequence.begin(); it < sequence.end(); ++it) {
        std::cin >> *it;
    }
    long long int leftBound, rightBound;
    std::cin >> leftBound >> rightBound;
    std::vector<long long int> prefixSums;
    prefixSums.resize(sequenceSize);
    std::partial_sum(sequence.begin(), sequence.end(), prefixSums.begin());
    int sum = CountSegment(prefixSums.begin(), prefixSums.end(), leftBound, rightBound);
    std::cout << sum;
    return 0;
}
