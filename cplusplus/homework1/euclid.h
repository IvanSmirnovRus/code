#include <algorithm>

int mod(int a, int b) {
    b = abs(b);
    return a > 0 ? a % b : b + a % b;
}

int gcdex_impl(int a, int b, int& u, int& v) {
    if (b == 0) {
        u = a / abs(a);
        v = 0;
        return abs(a);
    }
    int uTemp = 0, vTemp = 0;
    int d = gcdex_impl(b, mod(a, b), uTemp, vTemp);
    u = vTemp;
    v = uTemp - (a / b) * vTemp;   
    return d;
}

int gcdex(int a, int b, int& u, int& v) {
    bool flag = false;
    if (a < b) {
        flag = true;
        std::swap(a, b);
    }
    int k = 1, t = 1;
    if (a < 0) {
        k = -1;
        t = -1;
    } else if (b < 0) {
        k = 1;
        t = -1;
    }
    int d = gcdex_impl(abs(a), abs(b), u, v);
    u = u * k;
    v = v * t;
    if (flag) {
        std::swap(u, v);
    }
    return d;
}

bool invert(int a, int n, int& k) {
    int u, v;
    int d = gcdex(a, n, u, v);
    if (d != 1) {
        return false;
    } else {
        k = (u % n + n) % n;
        return true;
    }
}