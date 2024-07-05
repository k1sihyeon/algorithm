#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int N;
vector<pair<int, int>> matrix;
int dp[501][501];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> N;

    matrix.push_back({0, 0});
    
    for (int i = 1; i <= N; i++) {
        int r, c;
        cin >> r >> c;

        matrix.push_back({r, c});
    }

    for (int L = 1; L < N; L++) {
        for (int i = 1; i + L <= N; i++) {
            int j = i + L;
            dp[i][j] = 1e9;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + matrix[i].first * matrix[k].second * matrix[j].second);
            }
        }
    }

    cout << dp[1][N] << '\n';

    return 0;
}