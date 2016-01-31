#include <iostream>
#include <cmath>

using namespace std;

template <size_t X>
struct TFact {
	const static size_t value = X * TFact<X - 1>::value;
};

template <>
struct TFact<0> {
	const static size_t value = 1;
};

template <size_t N, size_t K>
struct TC {
	const static size_t value = TFact<N>::value / (TFact<K>::value * TFact<N - K>::value);
};

template <size_t N, size_t K>
struct TC2 {
	const static size_t value = TC2<N-1, K-1>::value + TC2<N-1, K>::value;
};

template <int N>
struct TC2<N, N> {
	const static size_t value = 1;
};

template <int N>
struct TC2<N, 1> {
	const static size_t value = N;
};

template <>
struct TC2<1, 1> {
	const static size_t value = 1;
};

int main()
{
	const size_t N = 1;
	const size_t K = 1;

	cout << TC<N, K>::value << endl;
	cout << TC2<N, K>::value << endl;
	return 0;
}