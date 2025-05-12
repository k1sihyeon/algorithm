#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int result = 0;
    vector<int> v;
    vector<int> dp;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        v.push_back(num);
        dp.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j] + v[i]);
        }

        result = max(result, dp[i]);
    }

    cout << result << "\n";

    return EXIT_SUCCESS;
}