#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct TDummy {
    int X;
    TDummy() = delete;
    explicit TDummy(int x) : X(x) {}
    TDummy(const TDummy&) = default;
    TDummy& operator= (const TDummy&) = delete;
    ~TDummy() { cout << "dtor for " << X << endl; }
};

template <typename T>
class TArray {
    T* Arr;
    size_t Cnt;
    size_t Capacity;

private:
    void FillSwap(const TArray& rhs, size_t capacity) {
        TArray tmp(max(capacity, rhs.Capacity));
        for (size_t i = 0; i < rhs.Cnt; ++i) {
            tmp.PushBack(rhs[i]);
        }
        swap(tmp);
    }

public:
    TArray(size_t capacity = 10)
        : Cnt(0)
        , Capacity(capacity) {
        Arr = static_cast<T*>(::operator new(sizeof(T) * Capacity));
    }

    TArray(const TArray& rhs) {
        FillSwap(rhs, rhs.Capacity);
    }

    ~TArray() {
        for (auto ptr = Arr; ptr < Arr + Cnt; ++ptr) {
            ptr->~T();
        }
        ::operator delete(Arr);
    }

    TArray& operator=(const TArray& rhs) {
        if (*this == &rhs) {
            return;
        }
        FillSwap(rhs, rhs.Capacity);
    }

    void swap(TArray& rhs) {
        ::swap(Arr, rhs.Arr);
        ::swap(Cnt, rhs.Cnt);
        ::swap(Capacity, rhs.Capacity);
    }
    T& operator[](size_t idx) {
        return Arr[idx];
    }
    const T& operator[](size_t idx) const {
        return Arr[idx];
    }
    void PushBack(const T& elem) {
        if (Cnt == Capacity) {
            FillSwap(*this, Capacity * 2);
        }
        new (static_cast<void*>(Arr + Cnt++)) T(elem);
    }
};