#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;

int main() {
    string input;
    while(getline(cin, input)) {
        std::vector<char> word;
        for(std::string::iterator it = input.begin(); it != input.end(); ++it) {
            word.push_back(*it);
        }
        int isPolindrome = 1;       
        for(std::vector<char>::const_iterator forwardIt = word.cbegin(), reverseIt = --word.cend();
            forwardIt <= reverseIt; ++forwardIt, --reverseIt) {
            if (*forwardIt != *reverseIt) {
                cout << "Not polindrome!" << std::endl;
                isPolindrome = 0;
                break;
            } 
        } 
        if(isPolindrome) {
            cout << "Polindrome!" << std::endl;
        }
    }
} 