include<iostream>
using namespace std;

int main() {
int a = 10;
int* ptr = a;
// Giải phóng con trỏ
delete ptr;
cout << local_var;

return 0;
}

// Khi chạy chương trình, sẽ xảy ra lỗi khi giải phóng con trỏ trỏ tới vùng nhớ của một biến địa phương.
// Việc sử dụng giá trị của biến địa phương sau khi con trỏ đã bị giải phóng có thể dẫn đến lỗi không xác định.
// Điều này xảy ra vì con trỏ đã trỏ tới một vùng nhớ mà không được cấp phát bằng new,
// vì vậy khi giải phóng con trỏ, chương trình sẽ cố gắng giải phóng một vùng nhớ mà không phải do nó cấp phát.
