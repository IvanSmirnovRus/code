#include <iostream>
#include <vector>

void FindAverage(const std::vector<float> &x, const std::vector<float> &y, float &px, float &py) {
    px = py = 0.0f;
    size_t cnt = x.size();
    if (cnt == 0 || cnt != y.size())
        return;
    for (size_t i = 0; i < cnt; ++i) {
        px += x[i];
        py += y[i];
    }
    px /= cnt;
    py /= cnt;
}

int main() {
    return 0;
}

