struct Point {
    int x;
    int y;
};
Point p = {3, 4};

cout << &p <<endl;
cout << &(p.x) << endl;
cout  << &(p.y) << endl;
