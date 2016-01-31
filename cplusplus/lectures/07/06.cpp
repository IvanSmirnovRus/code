#include <iostream>

struct T {
    T() { std::cout << "T created" << std::endl; }
    ~T() { std::cout << "T destroyed" << std::endl; }
};

struct T1 {
    T1() { std::cout << "T1 created" << std::endl; }
    ~T1() { std::cout << "T1 destroyed" << std::endl; }
};

void P() {
    static T t;
}

void P1() {
    static T1 t;
}


int main() {
    int n;
    std::cin >> n;
    if (n % 2 == 0) {
        P();
        P1();
    } else {
        P1();
        P();
    }
    return 0;
}

