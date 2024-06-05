#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

vector<int> graph[1001];
int visited[1001];
bool isCycle = false;

vector<int> result;

void DFS(int node) {
    visited[node] += 1;

    if (visited[node] >= 2) {
        isCycle = true;
        return;
    }

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        DFS(next);
    }

    result.push_back(node);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //init
    memset(visited, 0, sizeof(visited));

    //input
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
        }
    }

    //DFS
    for (int i = 1; i <= N; i++) {
        if (visited[i] == 0) {
            DFS(i);
        }
    }

    //output
    reverse(result.begin(), result.end());

    if ((result.size() != N) || isCycle)
        cout << 0;
    else
        for (int i = 0; i < N; i++)
            cout << result[i] << "\n";

    return 0;
}