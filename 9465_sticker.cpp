#include <iostream>

using namespace std;

#define MAX     100001

int dp[2][MAX];
int sticker[2][MAX];

inline int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;

    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                cin >> sticker[i][j];

        dp[0][0] = 0;
        dp[1][0] = 0;

        dp[0][1] = sticker[0][1];
        dp[1][1] = sticker[1][1];

        for (int i = 2; i <= N; i++) {
            dp[0][i] = sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] = sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }

        cout << max(dp[0][N], dp[1][N]) << "\n";
    }

    return 0;
}