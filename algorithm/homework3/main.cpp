#include <iostream>
#include <vector>
#include <list>

class MemoryPart {
public:
    size_t leftBorder;
    size_t rightBorder;
    size_t index;
    std::list<MemoryPart>::iterator it;

    bool isFree;

    size_t size() const {
        return  rightBorder - leftBorder + 1;
    }

    MemoryPart(size_t left, size_t right) : leftBorder(left), rightBorder(right) {}
};

struct MemoryPartCompare {
    bool operator() (const MemoryPart& firstPart, const MemoryPart& secondPart) {
        if (firstPart.size() != secondPart.size()) {
            return firstPart.size() < secondPart.size();
        }
        return firstPart.leftBorder > secondPart.leftBorder;
    }
};



template <typename T, typename Compare = MemoryPartCompare>
class THeap {
private:
    std::vector<T> elements;
    Compare comp;

    int getParent(size_t index) {
        return (index - 1) / 2;
    }

    int getLeftChild(size_t index) {
        return 2 * index + 1;
    }

    int getRightChild(size_t index) {
        return 2 * index + 2;
    }

    void swap(T& firstElement, T& secondElement) {
        std::swap(firstElement.it->index, secondElement.it->index);
        std::swap(firstElement, secondElement);
    }

    void siftUp(size_t index) {
        while (index > 0 && comp(getParent(index), elements[index])) {
            swap(elements[getParent(index)], elements[index]);
            index = getParent(index);
        }
    }

    void siftDown(size_t index) {
        while (getLeftChild(index) < elements.size()) {
            size_t maxIndex = getLeftChild(index);
            if (getRightChild(index) < elements.size() &&
                comp(elements[maxIndex], elements[getRightChild(index)])) {
                maxIndex = getRightChild(index);
            }
            if (!comp(elements[index], elements[maxIndex])) {
                return;
            } else {
                swap(elements[index], elements[maxIndex]);
                index = maxIndex;
            }
        }
    }
public:
    THeap<T, Compare> () {}

    THeap<T, Compare> (const T& element) {
        elements.push_back(element);
    }

    size_t size() const {
        return elements.size();
    }

    void insert(const T& element) {
        elements.push_back(element);
        siftUp(this->size() - 1);
    }

    void remove(typename std::vector<T>::iterator it) {
        swap(*it, *(elements.end() - 1));
        elements.pop_back();
        if (elements.size() > 0) {
            siftDown(it - elements.begin());
            siftUp(it - elements.begin());
        }
    }

    T extractMaximum() {
        T max = elements[0];
        remove(elements.begin);
        return max;
    }

    typename std::vector<T>::iterator begin() {
        return elements.begin();
    }

    typename std::vector<T>::const_iterator begin() const{
        return elements.begin();
    }

    typename std::vector<T>::iterator end() {
        return elements.end();
    }

    typename std::vector<T>::const_iterator end() const{
        return elements.end();
    }
};

class Manager {
private:
    THeap<MemoryPart> memoryHeap;
    std::vector<MemoryPart> allocMemory;
    std::list<MemoryPart> memoryParts;
public:
    Manager(const MemoryPart& part) :  memoryHeap(part) {
        memoryParts.push_back(part);
        memoryParts.begin()->index = 0;
        memoryHeap.begin()->it = memoryParts.begin();
    }

    size_t size() {
        return memoryHeap.size();
    }

    std::vector<MemoryPart>::iterator begin() {
        return memoryHeap.begin();
    }

    std::vector<MemoryPart>::const_iterator begin() const{
        return memoryHeap.begin();
    }

    std::vector<MemoryPart>::iterator end() {
        return memoryHeap.end();
    }

    std::vector<MemoryPart>::const_iterator end() const{
        return memoryHeap.end();
    }

    std::vector<MemoryPart>::iterator allocMemoryBegin() {
        return allocMemory.begin();
    }

    std::vector<MemoryPart>::const_iterator allocMemoryBegin() const{
        return allocMemory.begin();
    }

    std::vector<MemoryPart>::iterator allocMemoryEnd() {
        return allocMemory.end();
    }

    std::vector<MemoryPart>::const_iterator allocMemoryEnd() const{
        return allocMemory.end();
    }

    void allocate(int request) {
        if (size() == 0) {
            allocMemory.push_back();
        }
    }
};
int main() {
    return 0;
}