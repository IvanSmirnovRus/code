#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cout;
using std::endl;

void calcNGramms(const std::string& str,
                 size_t length,
                 std::map<std::string, size_t>* const result) 
{
    std::vector<std::string> nGramms;
    for (size_t start = 0; start + length <= str.size(); ++start) {
        std::string s = str.substr(start, length);

        if (result->find(s) == result->end()) {
            (*result)[s] = 0;
        }
        (*result)[s]++;    
    }
}

int main() {
    std::string s = "qwertyqweqwe";

    std::map<std::string, size_t> nGramms;
    calcNGramms(s, 3, &nGramms);

    for (std::map<std::string, size_t>::iterator it = nGramms.begin();
         it != nGramms.end();
         ++it) 
    {
         cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
