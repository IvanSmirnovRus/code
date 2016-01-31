#include <iostream>
#include "util.h"

int main(int argc, char const *argv[])
{
	int year;
	std::cin >> year;
	std::cout << IsLeapYear(year) << std::endl;
	return 0;
}