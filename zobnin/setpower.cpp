#include <iostream>

int Power(int base, int power) {
	if(power == 2) {
		return base * base;
	} else {
		if(power % 2) {
			return Power(base * base, (power - 1) / 2)  * base;
		} else {
			return Power(base * base, power / 2) ;
		}
	}
}
int powInd(int a,int n) {
  return (!n)?1:((n&1)?a:1)*powInd(a*a,n/2);
}


int main(int argc, char const *argv[]) {
	std::cout << Power(2, 10) << std::endl;
	std::cout << Power(2, 9) << std::endl;
	std::cout << powInd(2, 10) << std::endl;
	std::cout << powInd(2, 9) << std::endl;
	return 0;
}