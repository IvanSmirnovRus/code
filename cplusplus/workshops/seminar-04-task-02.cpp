#include <iostream>
#include <map>
#include <vector>

using std::cout;
using std::endl;
using std::make_pair;
using std::map;
using std::pair;
using std::string;
using std::vector;

bool findNextWord(const string& line, 
                  int startPosition,
                  int* wordBegin,
                  int* wordEnd,
                  char delimiter = ' ')
{
    int currentPosition = startPosition;

    // skip all delimiters
    while (currentPosition < line.size() && 
           line[currentPosition] == delimiter) 
    {
        ++currentPosition;
    }

    if (currentPosition < line.size()) {
        *wordBegin = currentPosition;

        // find word end
        while (currentPosition < line.size() && 
               line[currentPosition] != delimiter) 
        {
            ++currentPosition;
        }
        *wordEnd = currentPosition;
 
        return true;
    } else {
        return false;
    }
}

void makeIndex(const vector<string>& lines,
               map<string, vector<pair<int, int> > >* const result)
{
    result->clear();

    for (int lineIndex = 0; lineIndex < lines.size(); ++lineIndex) {
        const string& line = lines[lineIndex];

        int wordBegin, wordEnd;
        size_t position = 0;
        bool wordFound = findNextWord(line, position, &wordBegin, &wordEnd);
        while (wordFound) {
            string word = line.substr(wordBegin, wordEnd - wordBegin);
            (*result)[word].push_back(make_pair(lineIndex, wordBegin));

            position = wordEnd;
            wordFound = findNextWord(line, position, &wordBegin, &wordEnd);
        }
    }
}

int main() {
    vector<string> lines;
    lines.push_back("First test line");
    lines.push_back("   Second   test line");
    lines.push_back("Third very long test line    ");
    lines.push_back("  Last   test    string  ");
    map<string, vector<pair<int, int> > > index;
    makeIndex(lines, &index);

    for (map<string, vector<pair<int, int> > >::const_iterator indexIt =
             index.begin();
         indexIt != index.end();
         ++indexIt)
    {
        cout << indexIt->first << ": ";
        for (size_t i = 0; i < indexIt->second.size(); ++i) {
            cout << "(" << indexIt->second[i].first << ", " <<
                indexIt->second[i].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
