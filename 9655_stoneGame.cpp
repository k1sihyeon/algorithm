#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp;
    dp.resize(N);

    // int dp[1001];

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i-1] + 1, dp[i-3] + 1);
    }

    if (dp[N] % 2 == 0)
        cout << "CY" << "\n";
    else
        cout << "SK" << "\n";

    return EXIT_SUCCESS;
}