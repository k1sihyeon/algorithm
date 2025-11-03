#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int V;

vector<vector<pair<int, int>>> tree;
vector<bool> visited;

int maxDist = 0;
int maxNode = 0;

void dfs(int node, int dist) {
    if (visited[node])
        return;
    
    visited[node] = true;

    if (maxDist < dist) {
        maxDist = dist;
        maxNode = node;
    }

    for (const auto &next : tree[node]) {
        int nNode = next.first;
        int nDist = next.second;

        if (nNode != 0 && !visited[nNode]) {
            dfs(nNode, dist + nDist);
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> V;
    
    tree.assign(V + 1, vector<pair<int, int>>());
    visited.assign(V + 1, false);

    for (int i = 0; i < V; i++) {
        int node;
        cin >> node;

        while (true) {
            int next, dist;
            cin >> next;
            if (next == -1)
                break;
            cin >> dist;

            tree[node].push_back(make_pair(next, dist));
            tree[next].push_back(make_pair(node, dist));
        }
    }

    //dfs
    dfs(1, 0);

    visited.assign(V + 1, false);
    maxDist = 0;

    dfs(maxNode, 0);

    cout << maxDist << "\n";

    return 0;
}