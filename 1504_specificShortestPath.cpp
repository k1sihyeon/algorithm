#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 987654321;

int N, E;
int v1, v2;

vector<vector<pair<int, int>>> graph;
vector<int> costs;

void Dijkstra(int start) {
    costs.assign(N + 1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    costs[start] = 0;

    while (!pq.empty()) {
        int curCost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for (const auto &n : graph[cur]) {
            int next = n.first;
            int nextCost = n.second;

            if (nextCost + curCost < costs[next]) {
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
    cin >> N >> E;

    graph.resize(N + 1);
    costs.assign(N + 1, INF);

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    cin >> v1 >> v2;

    // Dijkstra
    Dijkstra(1);
    int oneToV1 = costs[v1];
    int oneToV2 = costs[v2];

    Dijkstra(v1);
    int v1Tov2 = costs[v2];
    int v1ToEnd = costs[N];

    Dijkstra(v2);
    int v2ToEnd = costs[N];

    long long res = min(oneToV1 + v1Tov2 + v2ToEnd, oneToV2 + v1Tov2 + v1ToEnd);

    if (res > INF || res < 0)
        cout << -1;
    else
        cout << res;

    return EXIT_SUCCESS;
}