#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int parent[1001];
vector<pair<int, pair<int, int>>> v; //cost, from, to

//kruskal

int Find(int a) {
    if (parent[a] == a)
        return a;

    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if (a != b)
        parent[b] = a;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = 0;

    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        v.push_back({c, {a, b}});
    }

    sort(v.begin(), v.end());

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 0; i < (int)v.size(); i++) {
        int cost = v[i].first;
        int from = v[i].second.first;
        int to = v[i].second.second;

        if (Find(from) != Find(to)) {
            Union(from, to);
            ans += cost;
        }
    }

    cout << ans << "\n";
    

    return 0;
}