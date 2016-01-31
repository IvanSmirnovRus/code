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

    void Print() const {
        std::cout << this->X << " " << Y << std::endl;
    }
};

int main() {
    TPoint a(1.0f), b(2.0f, -1.0f);
    a += b;
    a.Print();
    return 0;
}

