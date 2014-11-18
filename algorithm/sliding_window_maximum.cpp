#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iterator>

template <typename ValueType>
class MaxQueue {
public:
    MaxQueue();
    bool Empty() const;
    size_t Size() const;
    const ValueType& Head();
    const ValueType& Max();
    void Enqueue(const ValueType& val);
    void Dequeue();
private:
    std::stack<ValueType> tail;
    std::stack<ValueType> tailMaximum;
    std::stack<ValueType> head;
    std::stack<ValueType> headMaximum;
};

template <typename ValueType>
MaxQueue<ValueType>::MaxQueue() {}

template <typename ValueType>
bool MaxQueue<ValueType>::Empty() const {
    return tail.empty() && head.empty();
}

template <typename ValueType>
size_t MaxQueue<ValueType>::Size() const {
    return tail.size() + head.size();
}

template <typename ValueType>
const ValueType& MaxQueue<ValueType>::Head() {
    if (head.empty()) {
        while (!tail.empty()) {
            if (head.empty()) {
                headMaximum.push(tail.top());
                head.push(tail.top());
            } else {
                headMaximum.push(std::max(headMaximum.top(), tail.top()));
                head.push(tail.top());
            }
            tail.pop();
            tailMaximum.pop(); 
        }
        return head.top();
    } else {
        return head.top();
    }
}

template <typename ValueType>
const ValueType& MaxQueue<ValueType>::Max() {
    if (tail.empty()) {
        return headMaximum.top();
    } else {
        if (head.empty()) {
            return tailMaximum.top();
        } else {
        return std::max(tailMaximum.top(), headMaximum.top());
        }
    } 
}

template <typename ValueType>
void MaxQueue<ValueType>::Enqueue(const ValueType& val) {
    if (tail.empty()) {
        tailMaximum.push(val);
        tail.push(val);
    } else {
        tailMaximum.push(std::max(tailMaximum.top(), val));
        tail.push(val);
    }
}

template <typename ValueType>
void MaxQueue<ValueType>::Dequeue() {
    if (head.empty()) {
        while (!tail.empty()) {
            if (head.empty()) {
                headMaximum.push(tail.top());
                head.push(tail.top());
            } else {
                headMaximum.push(std::max(headMaximum.top(), tail.top()));
                head.push(tail.top());
            }
            tail.pop();
            tailMaximum.pop(); 
        }
        head.pop();
        headMaximum.pop();
    } else {
        head.pop();
        headMaximum.pop();
    }
}

void ReadVector(std::vector<int>* elements) {
    size_t size;
    std::cin >> size;
    elements->reserve(size);
    int element;
    for (int elementsCounter = 0; elementsCounter < size; ++elementsCounter) {
        std::cin >> element;
        elements->push_back(element);
    }
}
 
int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::vector<int> elements;
    ReadVector(&elements);
    size_t commandQuantity;
    std::cin >> commandQuantity;
    MaxQueue<int> queue;
    char command;
    size_t rBorder = 0;
    queue.Enqueue(elements[0]);
    std::vector<int> maximums;
    for (size_t commandCounter = 0; commandCounter < commandQuantity; ++commandCounter) {
        std::cin >> command;
        if (command == 'R') {
            ++rBorder;
            queue.Enqueue(elements[rBorder]);
            maximums.push_back(queue.Max());
        } else {
            queue.Dequeue();
            maximums.push_back(queue.Max());
        }
    }
    std::copy(maximums.begin(), maximums.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}



