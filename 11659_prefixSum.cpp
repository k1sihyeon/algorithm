#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
vector<int> prefixSum;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        v.push_back(num);

        if (i == 0)
            prefixSum.push_back(num);
        else
            prefixSum.push_back(prefixSum[i-1] + num);
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1; // idx 맞추기

        if (a == b)
            cout << v[a] << "\n";
        else if (a == 0)
            cout << prefixSum[b] << "\n";
        else
            cout << prefixSum[b] - prefixSum[a-1] << "\n";
    }

    return 0;
}