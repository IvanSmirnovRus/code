#include <iostream>

using std::cout;
using std::endl;

const int ATOI_BASE = 10;
const size_t MAX_INPUT_LINE_SIZE = 1024;

int atoi(const char* str) {
    int sign = 1;
    if (*str == '-') {
        sign = -1;
        ++str;
    }

    int result = 0;
    while (*str) {
        result *= ATOI_BASE; 
        result += *str - '0';
        ++str;
    }

    return sign * result;
}

int main() {
    char buffer[MAX_INPUT_LINE_SIZE];
    while (std::cin >> buffer) {
        cout << atoi(buffer) << endl;
    }

    return 0;
}
