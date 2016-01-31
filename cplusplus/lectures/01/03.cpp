#include <iostream>

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i <= n; ++i) {
        if (i % 2 == 0) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}

