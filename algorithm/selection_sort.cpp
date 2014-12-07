#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>


size_t GetIndexMinimum(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    int minimum = *begin;
    size_t indexMinimum = 0;
    for (std::vector<int>::iterator it = begin + 1; it < end; ++it) {
        if (*it < minimum) {
            minimum = *it;
            indexMinimum = it - begin;
        }
    }
    return indexMinimum;
}

void SelectionSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    for (std::vector<int>::iterator it = begin; it < end; ++it) {
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