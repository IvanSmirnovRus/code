#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include <time.h>
// ------------------------------------------------------------------------------------------------

void RandomVector(std::vector<long long int>* vector, int sid, size_t maxSize, long long int maxElement) {
    srand(sid);
    size_t sequenceSize = rand() % maxSize + 1;
    for (size_t index = 0; index < sequenceSize; ++index) {
        vector->push_back(rand() % (maxElement * 2) - maxElement);
    }
}

template <typename ForwardIterator>
void PrintContainer (ForwardIterator begin, ForwardIterator end) {
    if (begin + 1 <= end) {
        std::cout << *begin;
    }
    for (ForwardIterator it = begin + 1; it < end; ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;
}

template<typename RandomAccessIterator>
int CountSum(RandomAccessIterator begin, RandomAccessIterator end, 
                 long long int leftBound, long long int rightBound) {
    int sum = 0;
    for (RandomAccessIterator it = begin; it < end; ++it) {
        std::vector<long long int> prefixSums;
        prefixSums.resize(end - it);
        std::partial_sum(it, end, prefixSums.begin());
        for (RandomAccessIterator itt = prefixSums.begin(); itt < prefixSums.end(); ++itt) {
            if (*itt >= leftBound && *itt <= rightBound) {
                ++sum;
            }
        }
    }
    return sum;
}


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
    //std::cin.tie(nullptr);
    int i = 0;
    while(1) {
    std::vector<long long int> sequence;
    RandomVector(&sequence, i, 1000, 1000);
    //RandomVector(&sequence, i, 10, 20);
    //PrintContainer(sequence.begin(), sequence.end());
    long long int a, b;
    long long int leftBound, rightBound;
    a = rand() % 1000000 - 500000;
    b = rand() % 1000000 - 500000;
    if (a < b) {
        leftBound = a;
        rightBound = b;
    } else {
        leftBound = b;
        rightBound = a;
    }
    /*
    size_t sequenceSize;
    std::cin >> sequenceSize;
    std::vector<long long int> sequence(sequenceSize);
    for (std::vector<long long int>::iterator it = sequence.begin(); it < sequence.end(); ++it) {
        std::cin >> *it;
    }*/
    /*
    long long int leftBound, rightBound;
    std::cin >> leftBound >> rightBound;
    */
    std::vector<long long int> prefixSums;
    prefixSums.resize(sequence.size());
    std::partial_sum(sequence.begin(), sequence.end(), prefixSums.begin());
    int sum = CountSegment(prefixSums.begin(), prefixSums.end(), leftBound, rightBound);
    int summ = CountSum(sequence.begin(), sequence.end(), leftBound, rightBound);
    if(summ != sum) {
        std::cout << "NOT OK! " << i << '\t' << summ << '\t' << sum << std::endl;
        std::cout << sequence.size() << std::endl;
        PrintContainer(sequence.begin(), sequence.end());
        std::cout << leftBound << '\t' << rightBound << std::endl;
        std::cout << sum << std::endl;
        break;
    } else {
        std::cout << "OK! " << i << '\t' << summ << '\t' << sum << std::endl;
    }
    ++i;
    }
    return 0;
}
