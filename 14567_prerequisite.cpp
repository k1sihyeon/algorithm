#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
vector<int> graph[1001];
vector<int> indegree(1001, 0);
vector<int> result(1001, 0);

void topologicalSort() {
    queue<pair<int, int>> q;

    for (int i = 1; i <= N; i++)
        if (indegree[i] == 0)
            q.push({i, 1});
    
    while (!q.empty()) {
        int nNode = q.front().first;
        int nDepth = q.front().second;
        q.pop();

        result[nNode] = nDepth;

        for (int i = 0; i < (int)graph[nNode].size(); i++) {
            int next = graph[nNode][i];
            indegree[next] -= 1;

            if (indegree[next] == 0)
                q.push({next, nDepth+1});
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        indegree[to] += 1;
    }

    // solve
    topologicalSort();

    // output
    for (int i = 1; i <= N; i++)
        cout << result[i] << " ";

    return 0;
}