#include <iostream>

int Factorial(int n) {
    int res = 1;
    for (int i = 2; i <= n; ++i)
        res *= i;
    return res;
}

int main() {
    for (int i = 1; i <= 10; ++i)
        std::cout << i << "!=" << Factorial(i) << std::endl;
    /*std::cout << "Enter number: ";
    std::cin >> n;
    std::cout << "Result is ";
    std::cout << Factorial(n) << std::endl;*/
    return 0;
}

