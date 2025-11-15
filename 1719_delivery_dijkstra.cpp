#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

vector<vector<pair<int, int>>> graph;   // to, cost

vector<int> dist;
vector<int> path;

void dijkstra(int start) {
    //init
    dist.assign(n+1, 1e9);
    path.assign(n+1, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int curcost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (curcost > dist[cur])
            continue;

        for (auto &n : graph[cur]) {
            int next = n.first;
            int nextcost = curcost + n.second;

            if (nextcost < dist[next]) {
                dist[next] = nextcost;
                path[next] = cur;       // path 저장
                pq.push({nextcost, next});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    cin >> n >> m;
    
    //init
    graph.resize(n+1);

    // input
    for (int i = 0; i < m; i++) {
        int from, to, time;
        cin >> from >> to >> time;

        graph[from].push_back({to, time});
        graph[to].push_back({from, time});
    }

    // 모든 출발점마다 다익스트라
    for (int i = 1; i <= n; i++) {  // i == start
        dijkstra(i);

        for (int j = 1; j <= n; j++) {
            if (j == i) {
                cout << "- ";
                continue;
            }

            int idx = j;

            // 역추적
            while (path[idx] != i)
                idx = path[idx];

            cout << idx << " ";
        }

        cout << "\n";
    }

    return EXIT_SUCCESS;
}