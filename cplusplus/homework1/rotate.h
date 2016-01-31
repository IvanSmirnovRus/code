#include <algorithm>
#include <vector>

template <typename T> void RotateK(T begin, T end, int k) {
    int dist = std::distance(begin, end);
    if (dist == 0 || k % dist == 0) {
        return;
    }
    int shift = k % dist;
    if (k < 0) {
        shift = dist - std::abs(k) % dist;   
    }
    std::reverse(begin, end);
    std::reverse(begin, begin + shift);
    std::reverse(begin + shift, end);
}