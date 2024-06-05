#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N, M;

vector<int> graph[1001];
bool visited[1001];
bool finished[1001];

bool isCycle = false;

vector<int> result;

void DFS(int node) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        if (!visited[next])
            DFS(next);
        
        else if (!finished[next]) // 재방문 -> cycle
            isCycle = true;
    }

    result.push_back(node);
    finished[node] = true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //init
    memset(visited, false, sizeof(visited));
    memset(finished, false, sizeof(finished));

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
        if (!visited[i]) {
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