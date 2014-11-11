#include <iostream>

bool getBit (int data, int pos) {
	int mask = 1 << (pos - 1);
	return (data & mask) ? true : false;
}

void setBit (int * const data, int pos, bool value) {
	if(value) {
		int mask = 1 << (pos - 1);
		*data |= mask;
	} else {
		int mask = ~(1 << (pos - 1));
		*data &= mask;
	}
}

int main(int argc, char const *argv[]) {
	int data = 2;
	int * const ptr = &data;
	std::cout << getBit(data, 2) << std::endl;
	setBit(ptr, 1, true);
	std::cout << *ptr << std::endl;
	setBit(ptr, 2, false);
	std::cout << *ptr << std::endl;
	return 0;
}