#include <iostream>

int main() {
    /*const*/ int a = 1;
    int h = 7;
    const int & b = a;

    int * c = &a;
    *c = 2;
    c = &h;

    const int * d = &a;
    int const * e = &a;
    //*d = 3;
    //*e = 4;
    d = e = &h;

    int * const f = &a;
    *f = 5;
    //f = &h;
    
    const int * const g = &a;
    // *g = 8;
    //g = &h;

    return 0;
}

