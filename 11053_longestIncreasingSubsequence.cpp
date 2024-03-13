#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> dp;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
        dp.push_back(1);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        result = max(result, dp[i]);
    }

    cout << result << '\n';

    return 0;
}