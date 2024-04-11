#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        v.push_back(i);

    do {
        for (int i = 0; i < M; i++)
            cout << v[i] << ' ';
        cout << '\n';

        reverse(v.begin() + M, v.end());
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}