#include <iostream>
#include <cstring>

using namespace std;

int maxWindow[2][3];
int minWindow[2][3];

int N;
int max_result, min_result;

inline int Max(int a, int b) {
    return (a > b) ? a : b;
}

inline int Min(int a, int b) {
    return (a < b) ? a : b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    memset(maxWindow, 0, sizeof(maxWindow));
    memset(minWindow, 0, sizeof(minWindow));

    cin >> N;

    int k = 0;
    for (int i = 0; i < N; i++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;

        // max
        maxWindow[k][0] = Max(maxWindow[1-k][0], maxWindow[1-k][1]) + n1;
        maxWindow[k][1] = Max(Max(maxWindow[1-k][0], maxWindow[1-k][1]), maxWindow[1-k][2]) + n2;
        maxWindow[k][2] = Max(maxWindow[1-k][1], maxWindow[1-k][2]) + n3;

        // min
        minWindow[k][0] = Min(minWindow[1-k][0], minWindow[1-k][1]) + n1;
        minWindow[k][1] = Min(Min(minWindow[1-k][0], minWindow[1-k][1]), minWindow[1-k][2]) + n2;
        minWindow[k][2] = Min(minWindow[1-k][1], minWindow[1-k][2]) + n3;

        k = 1 - k;
    }

    max_result = Max(Max(maxWindow[1-k][0], maxWindow[1-k][1]), maxWindow[1-k][2]);
    min_result = Min(Min(minWindow[1-k][0], minWindow[1-k][1]), minWindow[1-k][2]);

    cout << max_result << " " << min_result << "\n";

    return 0;
}