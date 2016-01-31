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

    TPoint &operator += (const TPoint &rgt) {
        this->X += rgt.X;           // X += rgt.X;
        (*this).Y += rgt.Y;         // Y += rgt.Y;
        return *this;
    }

    //friend TPoint operator + (TPoint a, const TPoint &b) {
    //    return (a += b);
    //}
};

TPoint operator + (TPoint a, const TPoint &b) {
    //return TPoint(a.X + b.X, a.Y + b.Y);
    //TPoint tmp(a);
    //tmp += b;
    //return tmp;
    return (a += b);
}

int main() {
    TPoint a(1.0f), b(2.0f, -1.0f);
    a += b;
    std::cout << a.X << " " << a.Y << std::endl;
    return 0;
}

