#include <iostream>
#include <algorithm>
#include <vector>

struct Cube {
    int firstEdge, secondEdge, thirdEdge;
    friend bool operator<(const Cube &l, const Cube &r) {
        if (l.firstEdge < r.firstEdge && l.secondEdge < r.secondEdge 
        && l.thirdEdge < r.thirdEdge ) {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[]) {
    size_t cubesQuantity;
    std::cin >> cubesQuantity;
    std::vector<Cube> cubes;    
    Cube cube;
    for (size_t cubesCounter = 0; cubesCounter < cubesQuantity; ++cubesCounter) {
        std::cin >> cube.firstEdge;
        std::cin >> cube.secondEdge;
        std::cin >> cube.thirdEdge;
        cubes.push_back(cube);
    }
    std::vector<size_t> lisLength;
    lisLength.reserve(cubesQuantity);
    size_t lisMax = 1;
    for (size_t cubesCounterFirst = 0; cubesCounterFirst < cubes.size(); ++cubesCounterFirst) {
        lisLength[cubesCounterFirst] = 1;
        for (size_t cubesCounterSecond = 0; cubesCounterSecond < cubesCounterFirst;
        ++cubesCounterSecond) {
            if (cubes[cubesCounterSecond] < cubes[cubesCounterFirst] 
            && lisLength[cubesCounterSecond] >= lisLength[cubesCounterFirst]) {
                lisLength[cubesCounterFirst] = lisLength[cubesCounterSecond] + 1;
            }
        }
        if (lisLength[cubesCounterFirst] > lisMax) {
            lisMax = lisLength[cubesCounterFirst];
        }
    }
    std::cout << lisMax << std::endl;
    return 0;
}
