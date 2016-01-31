#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int FastPower(int base, int power) {
    int currentPower = 0;
    while (1 << currentPower <= power) {
        ++currentPower;
    }

    int result = 1;
    while (currentPower >= 0) {
        if (power & (1 << currentPower)) {
            result *= result * base;
        } else {
            result *= result;
        }
        --currentPower;
    }

    return result;
}

int main() {
    int base, power;
    cin >> base;
    cin >> power;
    cout << FastPower(base, power) << endl;
    return 0;
}

