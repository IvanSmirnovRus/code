#include <iostream>
#include <string>
#include <map>

using std::cout;
using std::endl;

int main() {
    std::map<std::string, int> wordsCounts;

    std::string word;
    while (std::cin >> word) {
        if (wordsCounts.find(word) == wordsCounts.end()) {
            wordsCounts[word] = 0;
        }
        ++wordsCounts[word];
    }

    for (std::map<std::string, int>::iterator iter = wordsCounts.begin();
         iter != wordsCounts.end();
         ++iter)
    {
        cout << iter->first << ": " << iter->second << endl;
    }

    return 0;
}
