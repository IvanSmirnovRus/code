#include <iostream>
#include <vector>
#include <string>
#include <stack>

bool isPair(char open, char close) {
    switch (open) {
        case '[':
            return ']' == close;
        case '(':
            return ')' == close;
        case '{':
            return '}' == close;
        default :
            return false;
    }
}

bool correct_sequence(const std::string& sequence, int* length) {
    std::stack<char> buffer;
    for (std::string::const_iterator it = sequence.begin(); it < sequence.end(); ++it) {
        switch (*it) {
            case '{':
            case '(':
            case '[':
                buffer.push(*it);
                ++(*length); 
                break;
            case '}':
            case ')':
            case ']':
                if (!buffer.empty() && isPair(buffer.top(), *it)) {
                    buffer.pop();
                    ++(*length);
                } else {
                    return false;
                }
                break;
            default :
                return false;
                break;
        }
    }
    if (buffer.empty()) {
        return true;
    } else {
        return false;
    }
}


int main() {
    std::string sequence;
    std::cin >> sequence;
    std::stack<std::string> buffer;
    int length = 0;
    if (correct_sequence(sequence, &length)) {
        std::cout << "CORRECT" << std::endl;
    } else {
        std::cout << length << std::endl;
    }
    return 0;
}
