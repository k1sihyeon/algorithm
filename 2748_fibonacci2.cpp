#include <iostream>
// #include <vector>

using namespace std;

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    // vector<long long> fibonacci(N, 0);
    long long *fibonacci = new long long[N];
    fill(&fibonacci[0], &fibonacci[N-1], 0);
    fibonacci[1] = 1;

    for (int i = 2; i <= N; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }

    cout << fibonacci[N] << "\n";

    return EXIT_SUCCESS;
}