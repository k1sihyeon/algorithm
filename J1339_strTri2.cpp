#include <bits/stdc++.h>

using namespace std;

char toChar(int num) {
    return (char)((num % 26) + 65);
}

char arr[100][100];
int n;

//help...

void solve(int num, int x, int y) {

    arr[x][y] = num;

    for (int i = x; i < num - x + 1; i++) {
        arr[i][y] = num++;
    }

    if (x == 0 && y == 0)
        return;

    solve(num, x-1, y-1);
}


int main(void) {
    cin >> n;

    if (n < 1 || n > 100 || n % 2 == 0) {
        cout << "INPUT ERROR" << "\n";
        return 0;
    }

    memset(arr, ' ', sizeof(arr));

    // int cnt = 0;
    // for (int j = 0; j < (n+1)/2; j++) {
    //     for (int i = 0; i < (j*2+1); i++) {
    //         arr[n/2+i-j][n/2-j] = toChar(cnt);
    //         cnt += 1;
    //     }
    // }

    solve(0, n/2, n/2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}