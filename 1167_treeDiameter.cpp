#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int V;
//int map[100001][100001] = {0, };
vector<pair<int, int>> tree[100001];
bool visited[100001];
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

    for (int i = 0; i < tree[node].size(); i++) {
        int nNode = tree[node][i].first;
        int nDist = tree[node][i].second;

        if (nNode != 0 && !visited[nNode]) {
            dfs(nNode, dist + nDist);
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, false, sizeof(visited));

    //input
    cin >> V;
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

    memset(visited, false, sizeof(visited));
    maxDist = 0;

    dfs(maxNode, 0);

    cout << maxDist << "\n";

    return 0;
}