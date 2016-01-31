#include <cmath>
#include <iostream>

using std::cout;
using std::endl;

static const double INPUT_PRECISION = 1e-9;
static const double OUTPUT_PRECISION = 1e-9;

double solve(double left, double right, double (*function)(double)) {
    // save values to call function as less times as possible
    double valueLeft = function(left);
    double valueRight = function(right);

    while (right - left > INPUT_PRECISION) {
        if (std::abs(valueLeft) < OUTPUT_PRECISION) {
            return left;
        } else if (std::abs(valueRight) < OUTPUT_PRECISION) {
            return right;
        } else {
            double middle = (left + right) / 2;
            double valueMiddle = function(middle);

            if (valueMiddle < 0) {
                left = middle;
                valueLeft = valueMiddle;
            } else {
                right = middle;
                valueRight = valueMiddle;
            }
        }
    }

    return left;
}

double TestFunction1(double x) {
    return std::sin(x) + 0.5;
}

double TestFunction2(double x) {
    return std::exp(x) - 2;
}

int main() {
    cout << "sin(x) + 0.5 on [-1, 1]: " << solve(-1, 1, TestFunction1) << endl;
    cout << "exp(x) - 2 on [0, 1]: " << solve(0, 1, TestFunction2) << endl;

    return 0;
}
