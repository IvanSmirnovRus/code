#include <iostream>

template<size_t k>
void Magic() {
    std::cout << "Hi, I'm generic Magic<" << k << ">" << std::endl;
}

template<>
void Magic<0>() {
    std::cout << "Hi, I'm Magic<0>" << std::endl;
}

int main() {
    Magic<3>();
    Magic<0>();
    size_t n;
    std::cin >> n;
    //Magic<n>(); // compilation error
    return 0;
}

