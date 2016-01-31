#include <iostream>
#include <vector>
#include <algorithm>
#include "prefix_sums.h"

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

int main(int argc, char const *argv[]) {
    size_t sequenceQuantity, sequenceSize;
    std::cin >> sequenceQuantity >> sequenceSize;
    std::vector<int> sequences(sequenceQuantity * sequenceSize);
    for (size_t sequenceIndex = 0; sequenceIndex < sequences.size(); ++sequenceIndex) {
        int elem;
        std::cin >> elem;
        sequences[sequenceIndex] = elem;
    }

    std::vector<int> output(sequences.size());
    PrefixSums(sequences.begin(), sequences.end(), output.begin());
    PrintContainer(output.begin(), output.end());

    for (size_t vectorSize = sequenceSize; vectorSize < sequences.size(); vectorSize *= 2) {
        for (std::vector<int>::iterator it = sequences.begin(); 
             it + vectorSize <  sequences.end(); it += 2 * vectorSize) {
            std::vector<int> result;
            if (it + 2 * vectorSize > sequences.end()) {
                result.resize(sequences.end() - it);
                std::merge(it, it + vectorSize, it + vectorSize, sequences.end() , result.begin());
            } else {
                result.resize(vectorSize * 2);
                std::merge(it, it + vectorSize, it + vectorSize,
                           it + 2 * vectorSize, result.begin());
            }
            std::copy(result.begin(), result.end(), it);
        }
    }
    PrintContainer(sequences.begin(), sequences.end());
    return 0;
}
