#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char const *argv[])
{
	typedef std::map<std::string, size_t> TStat;
	TStat stat;
	std::string word;
	std::ifstream fin("file.txt");
	while(fin >> word) {
		++stat[word];
	}
	for(TStat::const_iterator it=stat.begin(); it!=stat.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	return 0;
}
