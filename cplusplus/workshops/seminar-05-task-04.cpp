#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;


template <typename T, size_t Capacity>
class TLocalStack {
private:
	size_t Size_;
	T Data_[Capacity];

public:
	TLocalStack()
		: Size_(0)
	{}

	T& Top() {
		return Data_[Size_ - 1];
	}

	void Pop() {
		Size_ -= 1;
	}

	void Push(const T& element) {
		Data_[Size_] = element;
		++Size_;
	}
};

int main() {
	TLocalStack<int, 100> stack;

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