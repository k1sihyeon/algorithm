#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int V, E, K;

vector<vector<pair<int, int>>> graph;
vector<int> costs;

void Dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // 정점, 가중치

    pq.push({0, start});
    costs[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();

        if (costs[cur] < curCost) continue; // 이미 처리된 노드는 무시

        for (const auto &n : graph[cur]) {
            int next = n.first;
            int nextCost = curCost + n.second;

            if (nextCost < costs[next]) {
                costs[next] = nextCost;
                pq.push({nextCost, next});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 정점 개수, 간선 개수, 시작 정점 번호
    cin >> V >> E >> K;

    graph.resize(V + 1);
    costs.assign(V + 1, INF); // 정점 개수로 초기화

    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w; // u -> v (w)

        graph[u].push_back({v, w});
    }

    Dijkstra(K);

    for (int i = 1; i <= V; i++) {
        if (costs[i] < INF)
            cout << costs[i] << "\n";
        else
            cout << "INF" << "\n";
    }

    return EXIT_SUCCESS;
}