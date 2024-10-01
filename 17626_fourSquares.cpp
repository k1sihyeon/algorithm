#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);

    // 제곱 수는 자기자신의 제곱
    for (int i = 1; i * i <= N; i++)
        dp[i * i] = 1;

    for (int i = 1; i <= N; i++) {
        if (dp[i] != 0) 
            continue;   // 이미 갱신된 값이면 pass -> 제곱수
        
        for (int j = 1; j*j <= i; j++) {
            if (dp[i] == 0) // 갱신 되지 않은 값이면 바로 갱신
                dp[i] = dp[j*j] + dp[i - j*j]; 

            else
                dp[i] = min(dp[i], dp[j*j] + dp[i - j*j]);
        }
    }

    // 제곱 수의 최소 횟수와 그 제곱수를 뺀 최소 횟수
    // -> 비교

    cout << dp[N] << "\n";

    return 0;
}