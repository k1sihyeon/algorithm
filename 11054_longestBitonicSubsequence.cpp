#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    int result = 0;

    vector<int> v;
    vector<int> dpInc;
    vector<int> dpDec;

    cin >> N;

    dpInc.assign(N, 1);
    dpDec.assign(N, 1);

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (v[i] > v[j])
                dpInc[i] = max(dpInc[i], dpInc[j] + 1);
        }
    }

    for (int i = N-1; i >= 0; i--) {
        for (int j = N-1; j > i; j--) {
            if (v[i] > v[j])
                dpDec[i] = max(dpDec[i], dpDec[j] + 1);
        }
    }

    for (int i = 0; i < N; i++) {
        int sum = dpInc[i] + dpDec[i];
        result = max(result, sum);
    }

    cout << result - 1  << "\n";

    return EXIT_SUCCESS;
}