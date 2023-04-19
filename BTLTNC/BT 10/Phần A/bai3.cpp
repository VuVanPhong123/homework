#include <iostream>

struct Point {
    double x;
    double y;
};

Point mid_point(const Point& p1, const Point& p2) {
    Point mid;
    mid.x = (p1.x + p2.x) / 2.0;
    mid.y = (p1.y + p2.y) / 2.0;
    return mid;
}

int main() {
    Point p1 = {1.0, 2.0};
    Point p2 = {3.0, 4.0};

    Point mid = mid_point(p1, p2);

    std::cout << "Mid point: (" << mid.x << ", " << mid.y << ")" << std::endl;

    return 0;
}
