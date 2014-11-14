#include <iostream>
#include <vector>
#include <string>

bool isPair(char openBracket, char closeBracket) {
    switch (openBracket) {
        case '{' : 
            return '}' == closeBracket;
        case '[' :
            return ']' == closeBracket;
        case '(' :
            return ')' == closeBracket;
        default :
            return false;
    }
}

bool IsRegularBracketSequence(const std::string& sequence, size_t* const length) {
    *length = 0;
    std::vector<char> openBrackes;
    for (const char& bracket : sequence) {      
        switch (bracket) {
            case '{' :
            case '[' :
            case '(' :
                openBrackes.push_back(bracket);
                ++*length;
                break;
            case '}' :
            case ']' :
            case ')' : 
                if (openBrackes.empty() || !isPair(openBrackes.back(), bracket)) {
                    return false;
                } else {
                    openBrackes.pop_back();
                    ++*length;
                }
                break;
            default:
                return false;
        }
    }
    return openBrackes.empty();
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::string sequence;
    std::cin >> sequence;
    size_t length;
    if (IsRegularBracketSequence(sequence, &length)) {
        std::cout << "CORRECT" << std::endl;
    } else {
        std::cout << length << std::endl;
    }
    return 0;
}
