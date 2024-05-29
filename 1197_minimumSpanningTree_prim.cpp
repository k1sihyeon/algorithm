#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

//prim algorithm

int V, E, result = 0;
//vector<pair<int, pair<int, int>>> edges;    //cost, from, to //L
vector<pair<int, int>> edges[10001];          //cost, to //L

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool visited[10001];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(visited, false, sizeof(visited));

    cin >> V >> E;

    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({c, b});
        edges[b].push_back({c, a});
    }
        
    pq.push({0, 1});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        result += cost;

        for (int i = 0; i < edges[cur].size(); i++) {
            int next = edges[cur][i].second;
            int nextCost = edges[cur][i].first;
            
            if (!visited[next]) 
                pq.push({nextCost, next});
        }
    
    }

    cout << result << '\n';

    return 0;
}