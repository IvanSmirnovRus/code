#include <iostream>

int &P(int a, int b) {
    int s = a + b;
    return s;
}

int F(int n) {
    //int t;
    //std::cout << t << std::endl;
    if (n == 0 || n == 1) {
        return 1;
    }
    //t = 0;
    int a = F(n - 1);
    int b = F(n - 2);
    std::cout << "n=" << n
              << ": &a=" << &a
              << ", &b=" << &b << std::endl;
    return a + b;
}

int main() {
    int &s = P(2, 3);
    std::cout << s << std::endl;
    std::cout << "F(5)=" << F(5) << std::endl;
    std::cout << s << std::endl;
    return 0;
}

