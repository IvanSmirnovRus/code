#include <iostream>

int N = 100;

void Func1() {
    int a = 0;
    std::cout << "Func1 " << &N << " " << &a << std::endl;
}

void Func2() {
    int a = 0;
    std::cout << "Func2 " << &N << " " << &a << std::endl;
}

void Func3() {
    Func1();
    int a = 0;
    std::cout << "Func3 " << &N << " " << &a << std::endl;
}

int main() {
    Func1();
    Func2();
    Func3();
    return 0;
}

