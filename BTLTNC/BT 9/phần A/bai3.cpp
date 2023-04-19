char* a = new char[10];
char* c = a + 3;
for (int i = 0; i < 9; i++) a[i] = 'a';
a[9] = '\0';
cerr <<"a: " << "-" << a << "-" << endl;
cerr <<"c: " << "-" << c << "-" << endl;
delete[] a; // sửa lỗi bằng cách giải phóng toàn bộ mảng a
cerr << "a after deleting c:" << "-" << a << "-" << endl;
