#include <iostream>
#include <string>

using std::cout;
using std::endl;

int main() {
    std::string line;
    while (getline(std::cin, line)) {
        bool palindrom = true;
        for (size_t i = 0; i < line.size() / 2; ++i) {
            if (line[i] != line[line.size() - i - 1]) {
                palindrom = false;
                break;
            }
        }

        if (palindrom) {
            cout << "Palindrom" << endl;
        } else {
            cout << "Not a palindrom" << endl;
        }
    }

    return 0;
}
