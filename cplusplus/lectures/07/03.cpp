#include <iostream>

int F() {
    return 100;
}

int main() {
    int *pi = new int;
    int n = F();
    int *pia = new int[n];
    std::cout << pi << " " << pia << std::endl;
    delete pi;
    delete [] pia;
    return 0;
}

