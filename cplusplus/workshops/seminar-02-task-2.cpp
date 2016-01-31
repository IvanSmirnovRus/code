#include <iostream>

using std::cout;
using std::endl;

bool getBit(int data, int pos) {
    return (data & (1 << pos));
}

void setBit(int* const data, int pos, bool value) {
    if (value) {
        *data |= (1 << pos);
    } else {
        *data &= ~ (1 << pos);
    }
}

int main() {
    cout << getBit(255, 3) << endl;

    int data = 16;
    setBit(&data, 3, 1);
    cout << data << endl;
    return 0;
}

