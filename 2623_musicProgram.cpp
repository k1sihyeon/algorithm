#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;

vector<int> graph[1001];
int indegree[1001];  // 진입 차수

vector<int> result;

void topologicalSort();

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // init
    memset(indegree, 0, sizeof(indegree));

    // input
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int K, prev;
        cin >> K >> prev;

        // 1 4 3 을 1->4 4->3 으로 저장

        for (int j = 0; j < K - 1; j++) {
            int next;
            cin >> next;

            graph[prev].push_back(next);
            prev = next;

            indegree[next] += 1;
        }
    }

    // Topological Sort
    topologicalSort();

    // output
    if (result.size() != N)
        cout << 0;
    else
        for (int i = 0; i < N; i++)
            cout << result[i] << "\n";

    return 0;
}

void topologicalSort() {
    queue<int> q;

    // 1. 진입 차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // 2. 모든 노드에 대해
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // 3. 큐에서 뽑은 노드의 순서는 위상 정렬 결과
        result.push_back(node);

        for (int i = 0; i < graph[node].size(); i++) {
            // 해당 노드의 진출 노드(next)들의 진입차수를 1씩 감소
            int next = graph[node][i];
            indegree[next] -= 1;

            // 새롭게 진입차수가 0이 된 노드를 큐에 삽입
            if (indegree[next] == 0)
                q.push(next);
        }
    }
}