#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N, M;
int st, en;

vector<vector<pair<int, int>>> graph;
vector<int> costs;
vector<int> route;
vector<int> result;

void Dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    costs[start] = 0;

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (costs[cur] < curCost) continue;

        for (const auto &n : graph[cur]) {
            int next = n.first;
            int nextCost = n.second;

            if (nextCost + curCost < costs[next]) {
                route[next] = cur;

                costs[next] = nextCost + curCost;
                pq.push({costs[next], next});
            }
        }
    }
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    cin >> N >> M;

    graph.resize(N + 1);
    costs.assign(N + 1, INF);
    route.assign(N + 1, -1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    cin >> st >> en;

    // Dijkstra
    Dijkstra(st);

    // get route
    int idx = en;

    while (idx != -1) {
        result.push_back(idx);
        idx = route[idx];
    }

    reverse(result.begin(), result.end());

    // result
    cout << costs[en] << "\n";
    cout << result.size() << "\n";
    for (const auto &r : result)
        cout << r << " ";
    cout << "\n";
    
    return EXIT_SUCCESS;
}