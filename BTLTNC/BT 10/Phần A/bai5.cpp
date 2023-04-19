#include <iostream>
#include <cstring>

using namespace std;

struct ArrayStruct {
    int arr[10];
};

int main() {
    ArrayStruct a = {{0,1,2,3,4,5,6,7,8,9}};
    ArrayStruct b = a;

    // In địa chỉ của mảng arr trong các biến struct
    cout << a.arr << endl;
    cout << b.arr << endl;

    return 0;
}
