#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[]) {
    std::vector<std::string> v;
    std::string s;
    while (getline(std::cin, s)) {
        v.push_back(s);
    }

    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << std::endl;
    }
    
    return 0;
}