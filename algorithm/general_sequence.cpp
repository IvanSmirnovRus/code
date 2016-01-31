#include <iostream>
#include <vector>
#include <algorithm>

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

void input(std::vector<long long int>& firstSequence, std::vector<long long int>& secondSequence) {
    int firstSequenceSize, secondSequenceSize;
    std::cin >> firstSequenceSize;
    firstSequence.resize(firstSequenceSize);
    for (std::vector<long long int>::iterator it = firstSequence.begin(); 
         it != firstSequence.end(); ++it) {
        std::cin >> *it;
    }
    std::cin >> secondSequenceSize;
    secondSequence.resize(secondSequenceSize);
    for (std::vector<long long int>::iterator it = secondSequence.begin(); 
         it != secondSequence.end(); ++it) {
        std::cin >> *it;
    }
}

size_t LengthGeneralSequence(std::vector<long long int>& FirstSequence, 
                             std::vector<long long int>& SecondSequence,
                             std::vector<long long int>::iterator itEndFirstSequence, 
                             std::vector<long long int>::iterator itEndSecondSequence) {
    if (itEndFirstSequence == FirstSequence.begin() ||
        itEndSecondSequence == SecondSequence.begin()) {
        return 0;
    }
    if (*(itEndFirstSequence - 1) == *(itEndSecondSequence - 1)) {
        return LengthGeneralSequence(FirstSequence, SecondSequence,
                                    itEndFirstSequence - 1, itEndSecondSequence - 1) + 1;
    } else {
        return std::max(LengthGeneralSequence(FirstSequence, SecondSequence, 
                                              itEndFirstSequence - 1, itEndSecondSequence), 
                        LengthGeneralSequence(FirstSequence, SecondSequence,
                                              itEndFirstSequence, itEndSecondSequence - 1));
    }
}

int main(int argc, char const *argv[]) {
    std::vector<long long int> firstSequence, secondSequence;
    input(firstSequence, secondSequence);
    std::cout << LengthGeneralSequence(firstSequence, secondSequence, 
                                       firstSequence.end(), secondSequence.end()) << std::endl;
    return 0;
}
