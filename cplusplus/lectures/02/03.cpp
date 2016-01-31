#include <iostream>

struct A {
    A &operator ++ () {
        std::cout << "This is prefix form" << std::endl;
        return *this;
    }

    A operator ++ (int) {
        std::cout << "This is postfix form" << std::endl;
        A t(*this);
        ++(*this);
        return t;
    }
};

int main() {
    A a;
    ++a;
    a++;
    return 0;
}

