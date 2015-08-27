#include <iterator> 

template<typename RandomAccessInputIteratorm, typename RandomAccessOutputIteratorm>
void PrefixSums(RandomAccessInputIteratorm begin, RandomAccessInputIteratorm end,
                RandomAccessOutputIteratorm outBegin) {
    for (RandomAccessInputIteratorm itElements = begin; 
         itElements < end; ++itElements) {
        if (itElements == begin) {
            *outBegin = *itElements;
            ++outBegin;
        }  else {
            *outBegin = *itElements + *(std::prev(outBegin));
            ++outBegin;
        }
    }
}