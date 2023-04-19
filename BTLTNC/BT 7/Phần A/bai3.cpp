#include <iostream>

using namespace std;

int demMang(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (*(arr+i) % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int count1 = demMang(arr, 5);
    cout << "So phan tu chan trong doan 5 phan tu dau tien cua mang la: " << count1 << endl;
    int count2 = demMang(arr+5, 5);
    cout << "So phan tu chan trong doan 5 phan tu cuoi cung cua mang la: " << count2 << endl;

    return 0;
}
