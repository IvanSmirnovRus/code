#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <iterator>


void Enqueue(int element, std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (tail->empty()) {
        tailMaximum->push(element);
        tail->push(element);
    } else {
        tailMaximum->push(std::max(tailMaximum->top(), element));
        tail->push(element);
    }
}

void Dequeue(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (head->empty()) {
        while (!tail->empty()) {
            Enqueue(tail->top(), head, headMaximum);
            tail->pop();
            tailMaximum->pop();
        }
        head->pop();
        headMaximum->pop();
    } else {
        head->pop();
        headMaximum->pop();
    }
}

int HeadQueue(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (head->empty()) {
        while (!tail->empty()) {
            Enqueue(tail->top(), head, headMaximum);
            tail->pop();
            tailMaximum->pop();
        }
        return head->top();
    } else {
        return head->top();
    }
}

int TailQueue(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (tail->empty()) {
        while (!head->empty()) {
            Enqueue(head->top(), tail, tailMaximum);
            head->pop();
            headMaximum->pop();
        }
        return tail->top();
    } else {
        return tail->top();
    }
}

int MaxHeadQueue(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (head->empty()) {
        while (!tail->empty()) {
            Enqueue(tail->top(), head, headMaximum);
            tail->pop();
            tailMaximum->pop();
        }
        return headMaximum->top();
    } else {
        return headMaximum->top();
    }
}

int MaxTailQueue(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (tail->empty()) {
        while (!head->empty()) {
            Enqueue(head->top(), tail, tailMaximum);
            head->pop();
            headMaximum->pop();
        }
        return tailMaximum->top();
    } else {
        return tailMaximum->top();
    }
}

int GetMax(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    if (tail->empty()) {
        return headMaximum->top();
    } else {
        if (head->empty()) {
            return tailMaximum->top();
        } else {
        return std::max(MaxTailQueue(head, headMaximum, tail, tailMaximum),
        MaxHeadQueue(head, headMaximum, tail, tailMaximum));
        }
    }
}

void PrintQueue(std::stack<int>* head, std::stack<int>* headMaximum,
    std::stack<int>* tail, std::stack<int>* tailMaximum) {
    while (!head->empty() || !tail->empty()) {
        std::cout << HeadQueue(head, headMaximum, tail, tailMaximum) << std::endl;
        Dequeue(head, headMaximum, tail, tailMaximum);
    }
}

void ReadQueue(std::stack<int>* tail, std::stack<int>* tailMaximum) {
    size_t size;
    std::cin >> size;
    int element;
    for (size_t elementsCounter = 0; elementsCounter < size; ++elementsCounter) {
        std::cin >> element;
        Enqueue(element, tail, tailMaximum);
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
    std::stack<int> tail;
    std::stack<int> tailMaximum;
    std::stack<int> head;
    std::stack<int> headMaximum;
    char command;
    size_t rBorder = 0, lBorder = 0;
    Enqueue(elements[0], &tail, &tailMaximum);
    std::vector<int> maximums;
    for (size_t commandCounter = 0; commandCounter < commandQuantity; ++commandCounter) {
        std::cin >> command;
        if (command == 'R') {
            ++rBorder;
            Enqueue(elements[rBorder], &tail, &tailMaximum);
            maximums.push_back(GetMax(&head, &headMaximum, &tail, &tailMaximum));
        } else {
            ++lBorder;
            Dequeue(&head, &headMaximum, &tail, &tailMaximum);
            maximums.push_back(GetMax(&head, &headMaximum, &tail, &tailMaximum));
        }
    }
    std::copy(maximums.begin(), maximums.end(), std::ostream_iterator<int>(std::cout, " "));
    return 0;
}



