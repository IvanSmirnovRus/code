#include <iostream>
#include <vector>
#include "merge.h"

void InputVector(std::vector<int>& container, size_t Size) {
    int element;
    while(Size) {
        std::cin >> element;
        container.push_back(element);
        --Size;
    }
}

template <typename ForwardIterator>
void PrintContainer(ForwardIterator begin, ForwardIterator end) {
    for (ForwardIterator it = begin; it != end; ++it) {
        (it + 1) == end ? std::cout << *it : std::cout << *it << ' ';
    }
    std::cout << std::endl;
}


int main() {
    size_t firstVectorSize, secondVectorSize;
    std::cin >> firstVectorSize;
    std::vector<int> v1;
    InputVector(v1, firstVectorSize);
    std::cin >> secondVectorSize;
    std::vector<int> v2;
    InputVector(v2, secondVectorSize);
    std::vector<int> v3;
    util::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    PrintContainer(v3.begin(), v3.end());
    std::vector<int> v4;
    v4.resize(v1.size() + v2.size());
    std::vector<int>::iterator it = std::copy(v1.begin(), v1.end(), v4.begin());
    std::copy(v2.begin(), v2.end(), it);
    util::merge(v4.begin(), v4.begin() + v1.size(), v4.end());
    PrintContainer(v4.begin(), v4.end());
    return 0;
}