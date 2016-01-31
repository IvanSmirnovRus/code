#include <iostream>

int strlength(const char * str) {
	int counter = 0;
	while(str[counter] != 0) {
		++counter;
	}
	return counter;  
}

void printStr(char * input) {
	int size = strlength(input);
	for(int i = 0; i <= size; ++i) {
		std::cout << input[i];
	}
	std::cout << std::endl;
}

char * strcat(char * destination, const char * source) {
	int firstSize = strlength(destination);
	int secondSize = strlength(source);
	std::copy(source, source+secondSize, destination+firstSize);
	return destination;
}

char * strerr(char * destination, const char * source) {
	int firstSize = strlength(destination);
	int secondSize = strlength(source);
	char reverse[secondSize];
	for(int i=0; i <= secondSize; ++i) {
		reverse[i]=source[secondSize-i-1];
	}
	std::copy(reverse, reverse+secondSize, destination+firstSize);
	return destination;
}

int strcpm(const char * str1, const char * str2) {
	int firstSize = strlength(str1);
	int secondSize = strlength(str2);
	for(int i=0; i <= std::max(firstSize, secondSize); ++i) {
		if (i > firstSize) {
			return -1;
		}
		if (i > secondSize) {
			return +1;
		}
		if(str1[i] > str2[i]) {
			return +1;
		}
		if(str1[i] < str2[i]) {
			return -1;
		}
	}
	return +1;

}

int main(int argc, char const *argv[])
{
	char input[] = "Hello";
	//std::cout << strlength(input) << std::endl;
	//printStr(input);
	char second[] = ", world!";
	//printStr(strcat(input, second));
	//printStr(strerr(input, second));
	char str1[] = "Halloo";
	char str2[] = "Helloo";
	std::cout << strcpm(str1, str2) << std::endl;
	return 0;
}