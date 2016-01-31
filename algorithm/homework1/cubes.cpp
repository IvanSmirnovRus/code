#include <iostream>
#include <vector>

struct Cube {
    int firstEdge;
    int secondEdge;
    int thirdEdge;

    Cube() : firstEdge(0), secondEdge(0), thirdEdge(0) {}

    Cube(int first, int second, int third) :
    firstEdge(first), secondEdge(second), thirdEdge(third) 
    {}
    bool operator < (const Cube& cube) const {
        if (firstEdge < cube.firstEdge &&
            secondEdge < cube.secondEdge &&
            thirdEdge < cube.thirdEdge ) {
            return true;
        }
        return false;
    }

    void Print() const {
        std::cout << firstEdge << '\t' << secondEdge << '\t' << thirdEdge <<std::endl;
    }
};

void PrintVector (const std::vector<Cube>& Cubes) {
    for (std::vector<Cube>::const_iterator it = Cubes.begin(); it < Cubes.end(); ++it) {
        it->Print();
    }
}

void PrintVectorInt (const std::vector<int>& Cubes) {
    for (std::vector<int>::const_iterator it = Cubes.begin(); it < Cubes.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int cubesQuantity;
    int firstEdge, secondEdge, thirdEdge;
    std::vector<Cube> cubes;
    std::vector<int> sequenceLength;
    std::cin >> cubesQuantity;
    int maximum = 1;
    for (; cubesQuantity > 0; --cubesQuantity) {
        std::cin >> firstEdge >> secondEdge >> thirdEdge;
        cubes.push_back(Cube(firstEdge, secondEdge, thirdEdge));
        sequenceLength.push_back(1);
        for (size_t index = cubes.size(); index > 1; --index) {
            if (cubes[index - 2] < cubes[cubes.size() - 1] &&
                sequenceLength[cubes.size() - 1] < sequenceLength[index - 2] + 1) {
                sequenceLength[cubes.size() - 1] = sequenceLength[index - 2] + 1;
                if (sequenceLength[cubes.size() - 1] > maximum) {
                    maximum = sequenceLength[cubes.size() - 1];
                }
            }
        }
    }
    std::cout << maximum << std::endl;
    return 0;
}
