#include <bits/stdc++.h>
using namespace std;

long long dp[1001];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(dp, 0, sizeof(dp));

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i <= N; i++)
        dp[i] = (2 * dp[i - 2] + dp[i - 1]) % 10007;

    cout << dp[N] << "\n";

    return 0;
}