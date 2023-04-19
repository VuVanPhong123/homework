int* p = new int;
int* p2 = p;
*p = 10;
delete p;
p2 = new int; // Cấp phát một vùng nhớ mới cho p2
*p2 = 100;
cout << *p2;
delete p2;
