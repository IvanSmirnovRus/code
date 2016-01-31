#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>

using std::string;
using std::pair;
using std::map;
using std::vector;


void makeIndex(const vector<string>& lines, map<string, vector<pair<int, int> > > * const result) {
    pair<int, int> position;
    for (vector<string>::const_iterator itLine = lines.begin(); itLine < lines.end(); ++itLine) {
        string::const_iterator itStringBegin = itLine->begin();
        for(string::const_iterator itString = itLine->begin(); itString < itLine->end(); ++itString) {
            if (*(itString + 1) == ' ' || *(itString + 1) == '\t' || itString + 1 == itLine->end()) {
                string word = itLine->substr(itStringBegin - itLine->begin(), itString + 1 - itStringBegin);
                position = std::make_pair(itLine - lines.begin(), itStringBegin - itLine->begin());
                map<string, vector<pair<int, int> > >::iterator itKey = result->find(word);
                if(itKey == result->end()) {
                    std::vector<pair<int, int> > positions;
                    positions.push_back(position);
                    result->insert(pair<string, vector<pair<int, int> > > (word, positions));
                }
                else {
                    itKey->second.push_back(position);
                }
                itStringBegin = itString + 2;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<string> v;
    v.push_back("Hello World");
    v.push_back("World Hold on!");
    map<string, vector<pair<int, int> > > result;
    makeIndex(v, &result);
    for( map<string, vector<pair<int, int> > >::const_iterator it = result.begin(); it != result.end(); ++it) {
        std::cout << it->first; 
        for(vector<pair<int, int> >::const_iterator itPos = it->second.begin(); itPos < it->second.end(); ++itPos) {
            std::cout << '\t' << itPos->first << ',' << itPos->second;
        }
        std::cout << std::endl;
    }
    return 0;
}