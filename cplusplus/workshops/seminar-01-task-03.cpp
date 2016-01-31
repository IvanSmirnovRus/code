#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;

int main() {
    size_t contextSize = 3;
    std::string contextWord = "int";

    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.push_back(word);
    }

    for (size_t position = 0; position != words.size(); ++position) {
        if (words[position] == contextWord) {
            size_t contextBegin, contextEnd;

            if (position < contextSize) {
                contextBegin = 0;
            } else {
                contextBegin = position - contextSize;
            }

            if (position + contextSize + 1 > words.size()) {
                contextEnd = words.size();
            } else {
                contextEnd = position + contextSize + 1;
            }

            for (int i = contextBegin; i != contextEnd; ++i) {
                std::cout << words[i] << " ";
            }
            std::cout << std::endl;
        }
    }
}
