#include <iostream>
#include <list>
#include <vector>

using std::cout;
using std::endl;

template<typename TIn, typename TOut, typename TFunctor>
TOut copy_if(TIn begin, TIn end, TOut out, TFunctor predicate) {
    for (TIn it = begin; it != end; ++it) {
        if (predicate(*it)) {
            *out++ = *it;
        }
    }
}

bool IsOdd(int x) {
    return x % 2 != 0;
}

bool IsPowerOfTwo(int x) {
    while (x > 1) {
        if (x % 2 != 0) {
            return false;
        }
        x >>= 1;
    }

    return true;
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::vector<int> v(10, 0);
    copy_if(numbers, numbers + 10, v.begin(), IsOdd);
    for (std::vector<int>::const_iterator it = v.begin();
         it != v.end();
         ++it)
    {
        cout << *it << " ";
    }
    cout << endl;


    std::list<int> l(10, 0);
    copy_if(numbers, numbers + 10, l.begin(), IsPowerOfTwo);
    for (std::list<int>::const_iterator it = l.begin();
         it != l.end();
         ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
