#include <iostream>
#include <vector>

using namespace std;

int N, X;
vector<int> visits;
vector<int> dp;

int result = -1;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int maxVisits = -1;
    int maxCount = -1;

    // input
    cin >> N >> X;

    visits.resize(N + 1);
    dp.resize(N);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        visits[i] = num;
    }

    // 누적 합
    dp[0] = visits[0];
    for (int i = 1; i < N; i++) {
        dp[i] = dp[i - 1] + visits[i];
    }

    for (int i = 0; i <= N - X; i++) {
        int temp = dp[i+X - 1] - dp[i] + visits[i];

        if (temp > maxVisits) {
            maxVisits = temp;
            maxCount = 1;
        }
        else if (temp == maxVisits) {
            maxCount += 1;
        }
    }

    if (maxVisits == 0) {
        cout << "SAD" << "\n";
        return EXIT_SUCCESS;
    }

    cout << maxVisits << "\n" << maxCount << "\n";

    return EXIT_SUCCESS;
}