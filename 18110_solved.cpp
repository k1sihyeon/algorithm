#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;
    int N, sum = 0;
    cin >> N;

    if (N == 0) {
        cout << 0 << '\n';
        return 0;
    }
        
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int exclude = round(N * 0.15);

    for (int i = exclude; i < N - exclude; i++) {
        sum += v[i];
    }

    int size = N - 2 * exclude;
    int result = round((double)sum / size);
    cout << result << '\n';

    return 0;
}