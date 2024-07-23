#include <bits/stdc++.h>

using namespace std;

int n;
int board[100][100];

void snail(int num, int x, int y, bool goingDown) {
    if (num > n * n)
        return;

    board[x][y] = num;

    if (goingDown) {
        if (board[x][y + 1] == 0)  // 우
            snail(num + 1, x, y + 1, goingDown);

        else if (board[x + 1][y] == 0)  // 하
            snail(num + 1, x + 1, y, goingDown);

        else if (board[x][y - 1] == 0)  // 좌
            snail(num + 1, x, y - 1, goingDown);

        else if (board[x - 1][y] == 0)  // 상
            snail(num + 1, x - 1, y, !goingDown);
    }
    else {
        if (board[x - 1][y] == 0)  // 상
            snail(num + 1, x - 1, y, goingDown);

        else if (board[x][y + 1] == 0)  // 우
            snail(num + 1, x, y + 1, goingDown);

        else if (board[x + 1][y] == 0)  // 하
            snail(num + 1, x + 1, y, !goingDown);
    }
}

int main(void) {
    cin >> n;

    memset(board, -1, sizeof(board));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            board[i][j] = 0;
    }

    snail(1, 0, 0, true);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }

        cout << "\n";
    }

    return 0;
}