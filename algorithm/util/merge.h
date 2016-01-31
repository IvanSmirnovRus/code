//
// Created by Ivan G. Smirnov on 04.11.15.
//
#include <algorithm>
#include <vector>
#include <iterator>

class value_type;
namespace util {

    template<typename FirstInputIterator, typename SecondInputIterator, typename OutputIterator>
    void merge(FirstInputIterator FirstBegin, FirstInputIterator FirstEnd,
               SecondInputIterator SecondBegin, SecondInputIterator SecondEnd, OutputIterator result);

    template<typename FirstInputIterator, typename SecondInputIterator, typename OutputIterator>
    void merge(FirstInputIterator FirstBegin, FirstInputIterator FirstEnd,
               SecondInputIterator SecondBegin, SecondInputIterator SecondEnd, OutputIterator result) {
        while (true) {
            if (FirstBegin == FirstEnd) {
                std::copy(SecondBegin, SecondEnd, result);
                return;
            }
            if (SecondBegin == SecondEnd) {
                std::copy(FirstBegin, FirstEnd, result);
                return;
            }
            *result++ = (*FirstBegin < *SecondBegin) ? *FirstBegin++ : *SecondBegin++;
        }
    }

    template<typename  InputIterator>
    void merge(InputIterator begin, InputIterator middle, InputIterator end);

    template<typename InputIterator>
    void merge(InputIterator begin, InputIterator middle, InputIterator end) {
        typedef typename std::iterator_traits<InputIterator>::value_type T;
        std::vector<T> tmp(std::distance(begin, middle));
        std::copy(begin, middle, tmp.begin());
        util::merge(tmp.begin(), tmp.end(), middle, end, begin);
    }
}

