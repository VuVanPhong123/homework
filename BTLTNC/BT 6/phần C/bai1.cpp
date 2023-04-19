#include <iostream>

using namespace std;
bool isSafe(int x, int y, int* board) {
    for (int i = 0; i < x; i++) {
        if (board[i] == y || abs(x - i) == abs(board[i] - y)) {
            return false;
        }
    }
    return true;
}
void printBoard(int* board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) {
                cout << "* ";
            } else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
void solve(int k, int* board, int n) {
    if (k == n) {

        printBoard(board, n);
    } else {

        for (int i = 0; i < n; i++) {
            if (isSafe(k, i, board)) {

                board[k] = i;
                solve(k + 1, board, n);
                board[k] = -1;
            }
        }
    }
}

int main() {
    int n;
    cout << "Nhap kich thuoc ban co: ";
    cin >> n;
    int* board = new int[n];
    for (int i = 0; i < n; i++) {
        board[i] = -1;
    }
    solve(0, board, n);
    return 0;
}

