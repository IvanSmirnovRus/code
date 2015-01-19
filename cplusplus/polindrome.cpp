#include <iostream>
#include <string>
bool IsPolindrome(const std::string &word) {
	size_t length = word.size();
	for (int i = 0; i < length; ++i)
	{
		if(word[i] != word[length-i-1]) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	std::string word;
	while(getline(std::cin, word)) {
		if (IsPolindrome(word)) {
			std::cout << "Polindrome" << std::endl;
		}
		else {
			std::cout << "Not Polindrome" << std::endl;
		}
	}
	return 0;
}