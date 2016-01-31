#include <iostream>
#include <algorithm>

template <typename ForwardIterator>
void PrintContainer (ForwardIterator begin, ForwardIterator end) {
    if (begin + 1 <= end) {
        std::cout << *begin;
    }
    for (ForwardIterator it = begin + 1; it < end; ++it) {
        std::cout << ' ' << *it;
    }
    std::cout << std::endl;
}

template <typename T>
void Rotate(T begin, T end, int shift) {
    int size = end - begin;
    if (size == 0) {
        return;
    }
    shift = shift > 0 ? shift % size : size + (shift % size);
    while (shift) {
        for (T it = end - 1; it != begin; --it ) {
            std::swap(*it, *(it - 1));
        }
        --shift;
        }
}

bool IsLeapYear(int year) {
    if (year % 400 == 0) {
        return true;
    } else {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                return false;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }
}



int gcdex(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int xx;
        int yy;
        int dd;
        int d = gcdex(b, a % b, xx, yy);
        x = yy;
        y = xx - a / b * yy;
        return d;

    } 

}