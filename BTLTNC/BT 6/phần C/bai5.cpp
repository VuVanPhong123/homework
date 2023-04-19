#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void partition(int n, int max, int arr[], int i) {
    if (n == 0) {
        printArray(arr, i);
        return;
    }
    int start = (i == 0) ? 1 : arr[i - 1];
    for (int j = start; j <= max && j <= n; j++) {
        arr[i] = j;
        partition(n - j, j, arr, i + 1);
    }
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    partition(n, n, arr, 0);
    return 0;
}
