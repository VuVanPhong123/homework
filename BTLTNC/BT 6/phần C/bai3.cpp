#include <iostream>

using namespace std;

void Hoanvi(int N, int K, int index, int a[], int b) {
    if (index == K) {
        for (int i = 0; i < K; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = b; i <= N; i++) {
        a[index] = i;
        Hoanvi(N, K, index+1, a, i+1);
    }
}

int main() {
    int N ;
    int K;
    cin>>N>>K;
    int a[K];
    Hoanvi(N, K, 0, a, 1);

    return 0;
}
