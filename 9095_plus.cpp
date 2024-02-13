#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    int dp[11] = { 1, 2, 4, };
    cin >> T;

    for (int i = 0; i < T; i++) {
        int num;
        cin >> num;

        for (int j = 3; j < num; j++) {
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }

        cout << dp[num - 1] << '\n';
    }

    return 0;
}