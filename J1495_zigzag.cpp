#include <bits/stdc++.h>
using namespace std;

int n;
int board[101][101];

//goingDown이 true면 아래로, false면 위로
void Zigzag(int num, int x, int y, bool goingDown) {
    if (num > n*n)
        return;

    board[x][y] = num;

    if (goingDown) {
        if (x == n)
            Zigzag(num + 1, x, y + 1, !goingDown);      //right
        else if (y == 1)
            Zigzag(num + 1, x + 1, y, !goingDown);      //down
        else
            Zigzag(num + 1, x + 1, y - 1, goingDown);   //downLeft
    }
    else {
        if (y == n)
            Zigzag(num + 1, x + 1, y, !goingDown);      //down
        else if (x == 1)
            Zigzag(num + 1, x, y + 1, !goingDown);      //right
        else
            Zigzag(num + 1, x - 1, y + 1, goingDown);   //upRight
    }
}

int main(void) {
    cin >> n;

    memset(board, -1, sizeof(board));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            board[i][j] = 0;
        }
    }

    //board[1][1] = 1;
    //Down(2, 1, 1);

    Zigzag(1, 1, 1, true);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}


// void Down(int num, int x, int y);
// void Right(int num, int x, int y);
// void UpRight(int num, int x, int y);
// void DownLeft(int num, int x, int y);

// // 매개 변수는 현재 위치 넣기

// bool checkIdx(int x, int y) {
//     if (x >= 0 && x < n && y >= 0 && y < n) {
//         return true;
//     }
//     else {
//         cout << "\nIDX ERROR!!\n";
//         return false;
//     }
// }

// void Down(int num, int x, int y) {

//     if (board[x][y + 1] == -1 && board[x + 1][y] == -1)
//         return;

//     if (board[x + 1][y] == -1) {
//         Right(num, x, y);
//         //return;
//     }

//     if (board[x + 1][y] == 0)
//         board[x + 1][y] = num;

//     //???????????????????????????????????????????????????
//     if ((x % 2) == 0 && y == n) {
//         DownLeft(num + 1, x + 1, y - 1);
//         return;
//     }


//     UpRight(num + 1, x + 1, y);
// }

// void UpRight(int num, int x, int y) {
//     //cout << "upright: " << num << " " << x << " " << y << "\n";

//     if (board[x][y + 1] == -1 && board[x + 1][y] == -1)
//         return;

//     if (board[x - 1][y + 1] == -1) {
//         Right(num, x, y);
//         return;
//     }

//     if (board[x - 1][y + 1] == 0)
//         board[x - 1][y + 1] = num;

//     UpRight(num + 1, x - 1, y + 1);
// }

// void Right(int num, int x, int y) {
//     //cout << "right: " << num << " " << x << " " << y << "\n";

//     if (board[x][y + 1] == -1 && board[x + 1][y] == -1)
//         return;

//     if (board[x][y + 1] == -1) {
//         Down(num, x, y);
//         //return;
//     }

//     if (board[x][y + 1] == 0)
//         board[x][y + 1] = num;

//     //???????????????????????????????????????????????????
//     if (x == n && (y % 2) == 1) {
//         UpRight(num + 1, x, y + 1);
//         return;
//     }

//     DownLeft(num + 1, x, y + 1);
// }

// void DownLeft(int num, int x, int y) {
//     //cout << "downleft: " << num << " " << x << " " << y << "\n";

//     if (board[x][y + 1] == -1 && board[x + 1][y] == -1)
//         return;

//     if (board[x + 1][y - 1] == -1) {
//         Down(num, x, y);
//         return;
//     }

//     if (board[x + 1][y - 1] == 0)
//         board[x + 1][y - 1] = num;

//     DownLeft(num + 1, x + 1, y - 1);
// }