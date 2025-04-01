#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> dp;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    dp.assign(N+5, vector<int>(N+5, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> dp[i][j];
        }
    }

    int result = dp[1][1];

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i+1; j++) {
            if (j == 1) {   // 가장 왼쪽
                dp[i][j] += dp[i - 1][j];
            }
            else if (i == j) {  // 가장 오른쪽
                dp[i][j] += dp[i - 1][j - 1];
            }
            else {  // 중간에 있는 것들
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
            }

            result = max(result, dp[i][j]);
        }
    }

    cout << result << "\n";


    return EXIT_SUCCESS;
}