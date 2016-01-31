#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
struct TLessCmp {
	static unsigned int CmpCount;
	bool operator ()(const T& lhs, const T& rhs) {
		++CmpCount;
		return lhs < rhs;
	}
};

template <typename T>
unsigned int TLessCmp<T>::CmpCount = 0;

int main() {
	vector<int> v;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), TLessCmp<int>());
	cout << "vector size:\t" << v.size() << "\ncomparisons:\t" << TLessCmp<int>::CmpCount << endl;
}