#include <iostream>

using std::cout;
using std::endl;

char* itoa (unsigned int value, char* str, unsigned int base) {
    if (value == 0) {
        str[0] = '0';
        str[1] = 0;
        return str;
    }

    unsigned int maxPower = 1;
    while (maxPower < value) {
        maxPower *= base;
    }
    maxPower /= base;

    char* pstr = str;
    while (maxPower > 0) {
        *pstr = value / maxPower + '0';
        ++pstr;
        value %= maxPower;
        maxPower /= base;
    }
    *pstr = 0;

    return str;
}

int main() {
    char s[64];

    cout << itoa(7544, s, 7) << endl;

    return 0;
}
