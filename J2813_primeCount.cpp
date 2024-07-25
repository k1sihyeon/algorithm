#include <bits/stdc++.h>

using namespace std;

int M, N;
bool prime[3000001];

int main(void) {
    memset(prime, true, sizeof(prime));

    cin >> M >> N;

    for (int i = 2; i < sqrt(N); i++) {
        if (prime[i] == false)
            continue;
        
        for (int j = 2*i; j <= N; j += i)
            prime[j] = false;
    }

    prime[1] = false;

    int cnt = 0;
    for (int i = M; i <= N; i++) {
        if (prime[i])
            cnt += 1;
    }

    cout << cnt << "\n";

    return 0;
}