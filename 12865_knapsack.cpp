#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<pair<int, int>> items;
int dp[101][100001];

int main(void) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    items.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> items[i].first >> items[i].second;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            int weight = items[i].first;
            int value = items[i].second;

            if (weight <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[N][K] << '\n';

    return 0;
}