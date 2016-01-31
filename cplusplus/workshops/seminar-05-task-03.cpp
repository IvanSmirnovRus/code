#include <iostream>

using std::cout;
using std::endl;

template <typename T>
class TStack {
private:
    size_t Size_;
    size_t AllocatedSize_;
    T* Data_;

    static const size_t START_ALLOCATED_SIZE = 1;
    static const size_t REALLOCATION_MULTIPLY_RATE = 2;

public:
    TStack()
        : Size_(0)
        , AllocatedSize_(START_ALLOCATED_SIZE)
        , Data_(new T[AllocatedSize_])
    {}

    ~TStack() {
        delete[] Data_;
    }

    T& Top() {
        return Data_[Size_ - 1];
    }

    void Pop() {
        Size_ -= 1;
    }

    void Push(const T& element) {
        if (Size_ == AllocatedSize_) {
            size_t newAllocatedSize = 
                AllocatedSize_ * REALLOCATION_MULTIPLY_RATE;
            T* newData = new T[newAllocatedSize];

            for (size_t i = 0; i < Size_; ++i) {
                newData[i] = Data_[i];
            }

            delete[] Data_;
            Data_ = newData;
            AllocatedSize_ = newAllocatedSize;
        }

        Data_[Size_] = element;
        ++Size_;
    }
};

int main() {
    TStack<int> stack;

    cout << "Push 1" << endl;
    stack.Push(1);

    cout << "Push 2" << endl;
    stack.Push(2);

    cout << "Top: " << stack.Top() << endl;

    cout << "Push 3" << endl;
    stack.Push(3);

    cout << "Push 4" << endl;
    stack.Push(4);

    cout << "Pop" << endl;
    stack.Pop();

    cout << "Top: " << stack.Top() << endl;

    return 0;
}
