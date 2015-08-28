#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool CompareStrings(const std::string& str1, const std::string& str2) {

    size_t firstBeginPos = 0;
    size_t secondBeginPos = 0;
    while (str1[firstBeginPos] == '0') {
        ++firstBeginPos;
    }
    while (str2[secondBeginPos] == '0') {
        ++secondBeginPos;
    }
    size_t firstNumberLength = str1.length() - firstBeginPos;
    size_t secondNumberLength = str2.length() - secondBeginPos;

    return firstNumberLength == secondNumberLength ? 
    ((str1.compare(firstBeginPos, str1.length(), str2, secondBeginPos,  str2.length())) <= 0) :
    firstNumberLength < secondNumberLength;
}

void ReadStrings(std::vector<std::string>* strings) {
    std::string s;
    while(std::cin >> s) {
        strings->push_back(s);
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::string> strings;
    ReadStrings(&strings);
    std::sort(strings.begin(), strings.end(), CompareStrings);
    std::copy(strings.begin(), strings.end(), std::ostream_iterator<std::string>(std::cout, " "));
    std::cout << std::endl;
    return 0;
}