#include <iostream>
#include <vector>

using namespace std;

int N;
int ans = 0;
vector<pair<int, int>> v;

void DFS(int today, int sum) {
    if (today > N)
        return;
    
    ans = max(ans, sum);

    for (int i = today; i < N; i++)
        DFS(v[i].first + i, v[i].second + sum);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N;

    for (int i = 0; i < N; i++) {
        int T, P;
        cin >> T >> P;
        v.push_back({T, P});
    }

    DFS(0, 0);

    cout << ans << "\n";

    return 0;
}