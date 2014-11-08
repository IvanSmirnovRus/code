#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
    std::cout << "What's your name?\n";
    std::string s;
    //std::cin >> s;
    getline(std::cin, s);
    std::cout << "Hello, " << s << "\n";
    std::cout << "Hello" << ", " << "world!" << std::endl;
    return 0;
}