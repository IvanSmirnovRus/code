#include <iostream>

typedef bool (*TConditionFunc) (int);

size_t CountIf(int *a, size_t n, TConditionFunc cond) {
//size_t CountIf(int *a, size_t n, bool (*cond) (int)) {
    size_t res = 0;
    for (size_t i = 0; i < n; ++i) {
        if (cond(a[i])) {
            ++res;
        }
    }
    return res;
}

bool Less5(int a) {
    return (a < 5);
}

bool Greater3(int a) {
    return (a > 3);
}

bool Equal10(int a) {
    return (a == 10);
}

int main() {
    int A[] = {4, 10, 3, 2, 6, 9, 2, 10, 14};
    std::cout << CountIf(A, sizeof(A) / sizeof(A[0]), &Less5) << std::endl;
    std::cout << CountIf(A, sizeof(A) / sizeof(A[0]), &Greater3) << std::endl;
    std::cout << CountIf(A, sizeof(A) / sizeof(A[0]), &Equal10) << std::endl;
    return 0;
}

