#include <iostream>
#include <map>
#include <string>

using std::string;
using std::map;

void calcNGramms (const string& str, size_t n, map<string, size_t>* const result) {
	for (size_t index = 0; index + n <= str.size(); ++index) {
		string s = str.substr(index, n);
		++(*result)[s];
	}
}

void printMap(const map<string, size_t>& input) {
	for (map<string, size_t>::const_iterator it=input.begin(); it != input.end(); ++it) {
		std::cout << it->first << "\t" << it->second << std::endl;
	}
}

int main(int argc, char const *argv[])
{
	map<string, size_t> result;
	string input;
	input = "Hello, world. Hello, hello, baby. Baby, baby, baby.";
	calcNGramms(input, 4, &result);
	printMap(resu


































		
	return 0;
}