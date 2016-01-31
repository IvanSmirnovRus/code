#include <iostream>

template<size_t N>
struct TFactorial {
    static const size_t Result = TFactorial<N-1>::Result * N;
};

template<>
struct TFactorial<0> {
    static const size_t Result = 1;
};


template<size_t N, size_t K>
struct TCombinations {
    static const size_t Result =
        TCombinations<N-1, K-1>::Result +
        TCombinations<N-1, K>::Result;
};

template<size_t N>
struct TCombinations<N, 0> {
    static const size_t Result = 1;
};

template<size_t N>
struct TCombinations<N, N> {
    static const size_t Result = 1;
};

//template<>
//struct TCombinations<6, 2> {
//    static const size_t Result = 18;
//};


template<typename T>
struct TAlloc {
};

template<typename T, typename A = TAlloc<T> >
class TVector {
};

template<typename A>
class TVector<bool, A> {
};



int main() {
    std::cout << TFactorial<10>::Result << std::endl;
    std::cout << TCombinations<6, 2>::Result << std::endl;
    TVector<bool> bv;
    return 0;
}

