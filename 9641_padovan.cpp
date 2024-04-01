#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<long long> padovan(101, 0);
    int T, N;
    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;

        padovan[1] = padovan[2] = padovan[3] = 1;

        for (int j = 4; j <= N; j++) {
            padovan[j] = padovan[j - 2] + padovan[j - 3];
        }

        cout << padovan[N] << '\n';
    }

    return 0;
}