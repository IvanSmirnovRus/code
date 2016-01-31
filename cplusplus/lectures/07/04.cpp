#include <iostream>
#include <memory>

int main() {
    std::auto_ptr<int> pi(new int);
    *pi = 1;
    int *pia = new int[10];
    std::cout << pi.get() << " " << pia << std::endl;
    delete [] pia;
    return 0;
}

