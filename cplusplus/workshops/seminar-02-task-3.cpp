#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

size_t CountLeadingZeros(const std::string& s) {
    size_t zerosCount = 0;
    while (zerosCount < s.size() && s[zerosCount] == '0') {
        ++zerosCount;
    }
    return zerosCount;
}

bool CompareNumberStrings(const std::string& s1, const std::string& s2) {
    size_t start1 = CountLeadingZeros(s1);
    size_t start2 = CountLeadingZeros(s2);

    size_t len1 = s1.size() - start1;
    size_t len2 = s2.size() - start2;

    if (len1 < len2) {
        return true;
    } else if (len1 > len2) {
        return false;
    } else {
        return s1 < s2;
    }
}

int main() {
    std::vector<std::string> strings;

    std::string buf;
    while (cin >> buf) {
        strings.push_back(buf);
    }

    sort(strings.begin(), strings.end(), CompareNumberStrings);

    for (size_t i = 0; i < strings.size(); ++i) {
        cout << strings[i] << endl;
    }

    return 0;
}

