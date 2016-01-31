#include <iostream>

struct TPoint {
    float X;
    float Y;

    TPoint()
    {
        X = Y = 0.0f;
    }

    TPoint(float x)
        : X(x), Y(x)
    {
    }

    TPoint(float x, float y)
        : X(x), Y(y)
    {
    }
};

int main() {
    TPoint p(1.0f);
    return 0;
}

