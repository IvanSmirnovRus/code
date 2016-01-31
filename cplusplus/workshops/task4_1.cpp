#include <iostream>

double solve (double a, double b, double (*f)(double)) {
	double middle = ((b - a) / 2) + a;
	if (f(middle) == 0) {
		return middle;
	}

	if (f(middle) * f(b) < 0) {
		return solve(middle, b, f);
	}

	else {
		return solve(a, middle, f);
	}
}

double f(double a) {
	return a + 4;
}

int main(int argc, char const *argv[])
{
	double a = -10;
	double b = 10;
	double s = solve(a, b, f);

	std::cout <<  s << std::endl;
	return 0;
}