#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, X;

vector<vector<pair<int, int>>> adj;     //인접리스트
vector<vector<pair<int, int>>> adj_rev; //인접리스트 - 역방향

vector<int> dist;       //출발지에서 각 정점까지의 최단거리
vector<int> dist_rev;   //각 정점에서 출발지까지의 최단거리

void Dijkstra(int start, vector<vector<pair<int, int>>> &adj, vector<int> &dist) {
    
    dist[start] = 0;

    //오름차순 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({start, 0});

    while (!pq.empty()) {
        int here = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        //가중치가 더 크면 무시
        if (dist[here] < cost) continue;

        //인접한 정점들을 모두 검사
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            
            //더 짧은 경로를 발견하면 갱신
            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({there, nextDist});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> N >> M >> X;

    adj = vector<vector<pair<int, int>>>(N + 1);
    adj_rev = vector<vector<pair<int, int>>>(N + 1);

    dist = vector<int>(N + 1, 1e9);
    dist_rev = vector<int>(N + 1, 1e9);

    for (int i = 0; i < M; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;

        adj[from].push_back({to, weight});
        adj_rev[to].push_back({from, weight});
    }

    //다익스트라
    Dijkstra(X, adj, dist);
    Dijkstra(X, adj_rev, dist_rev);

    //최장거리 구하기
    int max_dist = 0;
    for (int i = 1; i <= N; i++)
        max_dist = max(max_dist, dist[i] + dist_rev[i]);

    cout << max_dist << '\n';

    return 0;
}