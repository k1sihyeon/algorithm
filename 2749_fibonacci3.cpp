#include <iostream>
#include <cmath>

using namespace std;

// 피사노 주기
// P = π(M) 라고 할 때, Fn mod M = F(n mod P) mod M
// mod 1000000(10^6)의 주기 P는 15 * 10^(6-1) = 1500000

const long long mod = 1000000LL;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long N;
    cin >> N;

    long long period = 15LL * (mod / 10LL);
    long long K = N % period;

    long long *fibonacci = new long long[period];
    fill(&fibonacci[0], &fibonacci[period-1], 0);
    fibonacci[1] = 1;

    for (int i = 2; i <= period; i++) {
        fibonacci[i] = (fibonacci[i-1] + fibonacci[i-2]) % mod;
    }

    cout << fibonacci[K] << "\n";

    return EXIT_SUCCESS;
}