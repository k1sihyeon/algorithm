#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int N, maxDist, maxNode;

void dfs(int node, int dist) {
    if (visited[node])
        return;

    visited[node] = true;

    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        int next = tree[node][i].first;
        int nextDist = tree[node][i].second;

        if (!visited[next]) {
            dfs(next, dist + nextDist);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int node, next, dist;
        cin >> node >> next >> dist;

        tree[node].push_back({next, dist});
        tree[next].push_back({node, dist});
    }

    memset(visited, false, sizeof(visited));
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDist = 0;

    dfs(maxNode, 0);
    cout << maxDist << '\n';

    return 0;
}