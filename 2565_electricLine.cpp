#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ans = 0;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;

        v.push_back({a, b});
    }

    sort(v.begin(), v.end());

    vector<int> dp(N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i].second > v[j].second)
                dp[i] = max(dp[i], dp[j] + 1);
        }

        ans = max(ans, dp[i]);
    }

    cout << N - ans << '\n';

    return 0;
}