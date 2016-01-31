#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>

void input(std::vector<std::pair<int, int> >& points, int& PointCount) {
    size_t pointsQuantity;
    std::cin >> pointsQuantity;
    std::cin >> PointCount;
    int xx, yy;
    for (size_t pointIndex = 0; pointIndex < pointsQuantity; ++pointIndex) {
        std::cin >> xx;
        std::cin >> yy;
        points.push_back(std::pair<int, int> (xx, yy));
    }
}

struct TPoint {
    double Xcor;
    int Type;
    TPoint (double xcor, int type) : Xcor(xcor), Type(type) {}; 
    bool operator< (const TPoint& other) const {
        if (fabs(Xcor - other.Xcor) < 1e-6) {
            return Type < other.Type;
        } else {
            return Xcor < other.Xcor;
        }
    }
};

bool GetCoveredSegment(std::pair<int, int> point, double radius, 
                       std::pair<double, double>& result) {
    point.second = abs(point.second);
    if (fabs(radius * radius - point.second * point.second) < 1e-6) {
        result.first = result.second = point.first;
        return true;
    }
    if (radius * radius - point.second * point.second < 0) {
        return false;
    }
    double distance = sqrt(radius * radius - point.second * point.second);
    result.first = point.first - distance;
    result.second = point.first + distance;
    return true;
}

bool Check(std::vector<std::pair<int, int> >& points, double radius, int PointCount) {
    std::vector<TPoint> result;
    for (std::vector<std::pair<int, int> >::iterator it = points.begin(); 
         it != points.end(); ++it) {
        std::pair<double, double> Segment;
        if (GetCoveredSegment(*it, radius, Segment)) {
            result.push_back(TPoint(Segment.first, 0));
            result.push_back(TPoint(Segment.second, 1));
        }
    }
    std::sort(result.begin(), result.end());
    size_t counter = 0;
    for (std::vector<TPoint>::iterator it = result.begin(); it != result.end(); ++it) {
        if (it->Type) {
            --counter;
        } else {
            ++counter;
        }
        if (counter >= PointCount) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[]) {
    int kk;
    std::vector<std::pair<int, int> > points;
    input(points, kk);
    double begin = 0, end = 2000;
    while (end - begin > 0.0001) {
        double middle = (end - begin) / 2.0 + begin;
        if (Check(points, middle, kk)) {
            end = middle;
        } else {
            begin = middle;
        }
    }
    printf("%.6lf\n", begin);
    return 0;
}
