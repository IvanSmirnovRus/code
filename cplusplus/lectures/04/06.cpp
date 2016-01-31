#include <iostream>
#include <algorithm>

struct TPoint {
    float X;
    float Y;

    TPoint()
    {
        X = Y = 0.0f;
    }

    TPoint(float x, float y)
        : X(x), Y(y)
    {
        std::cout << "Hello, I'm the constructor" << std::endl;
    }

    ~TPoint() {
        std::cout << "Hello, I'm the destructor" << std::endl;
    }

    TPoint &operator = (const TPoint &rgt) {
        TPoint tmp(rgt);
        tmp.Swap(*this);
        return *this;
    }

    void Swap(TPoint &rgt) {
        std::swap(X, rgt.X);
        std::swap(Y, rgt.Y);
    }

    TPoint &operator += (const TPoint &rgt) {
        this->X += rgt.X;           // X += rgt.X;
        (*this).Y += rgt.Y;         // Y += rgt.Y;
        return *this;
    }

    void Print() const {
        std::cout << this->X << " " << Y << std::endl;
    }
};

int main() {
    TPoint a(1.0f, 0.0f);
    for (size_t i = 0; i < 10; ++i ) {
        TPoint b(2.0f, -1.0f);
        a += b;
    }
    TPoint c, d(a);
    c = a;
    c.Print();
    return 0;
}

