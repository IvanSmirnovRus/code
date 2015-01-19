#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void merge(const std::vector<int>& first, 
           const std::vector<int>& second, std::vector<int>* result) {
    result->reserve(first.size() + second.size());
    std::vector<int>::const_iterator it1, it2;
    for (it1 = first.begin(), it2 = second.begin();
         it1 != first.end() && it2 != second.end(); ) {
        (*it1 <= *it2) ? result->push_back(*it1++) : result->push_back(*it2++);
        
    }
    std::copy(it1, first.end(), std::back_inserter(*result));
    std::copy(it2, second.end(), std::back_inserter(*result));

}

void PrintVector(const std::vector<int>& vect) {
    for (auto const & elem: vect) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void ReadVector(std::vector<int>& vect) {
    size_t size;
    std::cin >> size;
    vect.resize(size);
    for (size_t i = 0; i < size; ++i) {
        std::cin >> vect[i];
    }
} 

int main(int argc, char const *argv[]) {
    std::vector<int> first;
    std::vector<int> second;
    ReadVector(first);
    ReadVector(second);
    std::vector<int> result;
    merge(first, second, &result);
    PrintVector(result);
    return 0;
}