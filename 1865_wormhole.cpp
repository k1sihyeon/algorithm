#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

bool isNegativeCycle(int start, int v, int e, vector<int> & dist, vector<vector<pair<int, int>>> & graph);

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;

    for (int i = 0; i < TC; i++) {
        int N, M, W;

        cin >> N >> M >> W;

        vector<vector<pair<int, int>>> graph(N + 1);
        vector<int> dist(N + 1, INF);

        for (int j = 0; j < M; j++) {   // 도로 - 무방향, 양수 가중치
            int S, E, T;
            cin >> S >> E >> T;

            graph[S].push_back({E, T});
            graph[E].push_back({S, T});
        }


        for (int j = 0; j < W; j++) {   // 웜홀 - 방향, 음수 가중치
            int S, E, T;
            cin >> S >> E >> T;

            graph[S].push_back({E, -T});
        }

        //시간이 줄어들면서 어떠한 출발 위치로 돌아옴 -> 음수 간선 순환
        
        bool flag = false;

        for (int start = 1; start <= N; start++) {
            if (isNegativeCycle(start, N, M + W, dist, graph)) {
                cout << "YES" << "\n";
                flag = true;
                break;
            }
        }

        if (!flag)
            cout << "NO" << "\n";
    }

    return EXIT_SUCCESS;
}


bool isNegativeCycle(int start, int v, int e, vector<int> & dist, vector<vector<pair<int, int>>> & graph) {
    dist.assign(v + 1, INF);
    dist[start] = 0;

    for (int i = 0; i < v - 1; i++) {

        bool updated = false;

        for (int j = 1; j <= v; j++) {
            for (const auto & n : graph[j]) {
                int next = n.first;
                int nextCost = dist[j] + n.second;

                if ((nextCost < dist[next]) && (dist[j] != INF)) {
                    dist[next] = nextCost;

                    updated = true;
                }
            }
        }

        if (!updated)
            return false;
    }

    for (int i = 1; i <= v; i++) { 
        for (const auto & n : graph[i]) {
            int next = n.first;
            int nextCost = dist[i] + n.second;

            if ((nextCost < dist[next]) && (dist[i] != INF)) {
                return true;
            }
        }
    }

    return false;
}