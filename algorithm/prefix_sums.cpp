void PrefixSums(const std::vector<int>& elements, std::vector<int>* prefixSums) {
    for (std::vector<int>::const_iterator itElements = elements.begin(); 
         itElements < elements.end(); ++itElements) {
        if (itElements == elements.begin()) {
            prefixSums->push_back(*itElements);
        }  else {
            prefixSums->push_back(*itElements + prefixSums->back());
        }
    }
}