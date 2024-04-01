#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, start, dest;
vector<vector<pair<int, int>>> bus;
vector<int> cost;

void Dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(start, 0));
    cost[start] = 0;

    while (!pq.empty()) {
        int cur = pq.top().first;
        int curCost = pq.top().second;
        pq.pop();

        //가중치가 더 크면 무시
        if (cost[cur] < curCost)
            continue;
        
        //인접한 정점들을 모두 검사
        for (int i = 0; i < bus[cur].size(); i++) {
            int next = bus[cur][i].first;
            int nextCost = curCost + bus[cur][i].second;

            if (nextCost < cost[next]) {
                cost[next] = nextCost;
                pq.push(make_pair(next, nextCost));
            }
        }
    }

    cout << cost[dest] << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    bus.resize(N + 1);
    cost.resize(N + 1, 1e9);

    for (int i = 0; i < M; i++) {
        int a, b, costN;
        cin >> a >> b >> costN;

        bus[a].push_back(make_pair(b, costN));
        cost.push_back(costN);
    }

    cin >> start >> dest;

    Dijkstra();

    return 0;
}