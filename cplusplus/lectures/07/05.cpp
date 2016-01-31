#include <iostream>

int N;

int &P(int a, int b) {
    static int s;
    s = a + b;
    return s;
}

int main() {
    int &s = P(2, 3);
    std::cout << s << std::endl;
    std::cout << P(2, 2) << std::endl;
    std::cout << s << std::endl;
    std::cout << &N << " " << &s << std::endl;
    return 0;
}

