#include <iostream>

void Magic(char *a, char *b) {
    while (*(a++) = *(b++));
}

int main() {
    char a[100], b[100] = "Hello, world!";
    Magic(a, b);
    std::cout << a << std::endl;
    return 0;
}

