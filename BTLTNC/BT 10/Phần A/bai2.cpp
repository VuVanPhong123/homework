#include <iostream>
using namespace std;
struct Point {
    int x;
    int y;
};

void print(Point p) {
    cout << "(" << p.x << ", " << p.y << ")" << endl;
}
void pass_by_value(Point p) {
    print(p);
    p.x = 10;
    p.y = 20;
    print(p);
}

void pass_by_reference(Point &p) {
    print(p);
    p.x = 10;
    p.y = 20;
    print(p);
}

int main() {
    Point p = {3, 4};

    cout << "dia chi p" << &p << endl;
    pass_by_value(p);
    cout << "sau khi goi ham, dia chi p la ";
    print(p);

    cout << "dia chi p " << &p << endl;
    pass_by_reference(p);
    cout << "sau khi goi ham dia chi p la ";
    print(p);

    return 0;
}
