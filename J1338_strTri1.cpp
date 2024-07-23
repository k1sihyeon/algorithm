#include <bits/stdc++.h>

using namespace std;

char arr[100][100];

char toChar(int num) {
    return (char)((num % 26) + 65);
}

int main(void) {

    int n;
    cin >> n;

    memset(arr, ' ', sizeof(arr));

    int cnt = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            arr[j + i][n - (i+1)] = toChar(cnt);
            cnt += 1;
        }

    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }

        cout << "\n";
    }
    

    return 0;
}