#include <iostream>
#include <string>

int operator + (int a, const std::string &b) {
    return a;
}

int main() {
    int k = 1;
    std::cout << 1 + "str" << std::endl;
    std::cout << k + "str" << std::endl;
    std::cout << 1 + std::string("str") << std::endl;
    std::cout << k + std::string("str") << std::endl;
    return 0;
}

