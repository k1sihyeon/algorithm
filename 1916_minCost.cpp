#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, start, dest;
vector<pair<int, int>> bus;
vector<int> cost;

void Dijkstra() {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    cost[start] = 0;

    while (!pq.empty()) {
        int curCost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (cost[cur] < curCost)
            continue;
        
        //
        for (int i = 0; i < bus.size(); i++) {
            if (bus[i].first == cur) {
                int next = bus[i].second;
                int nextCost = curCost + cost[i];

                if (nextCost < cost[next]) {
                    cost[next] = nextCost;
                    pq.push(make_pair(-nextCost, next));
                }
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

    for (int i = 0; i < M; i++) {
        int a, b, costN;
        cin >> a >> b >> costN;

        bus.push_back(make_pair(a, b));
        cost.push_back(costN);
    }

    cin >> start >> dest;

    Dijkstra();

    return 0;
}