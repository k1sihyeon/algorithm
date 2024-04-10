#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
vector<int> graph[32001];
bool visited[32001];
vector<int> result;

void DFS(int node) {
    visited[node] = true;

    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];

        if (!visited[next])
            DFS(next);
    }

    result.push_back(node);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;

    memset(visited, false, sizeof(visited));

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        graph[a].push_back(b);  //그래프 표현
    }

    //학생마다 DFS
    for (int i = 1; i <= N; i++) {
        if (!visited[i])
            DFS(i);
    }

    //dfs 결과를 뒤집어서 출력
    reverse(result.begin(), result.end());

    //출력
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    
    return 0;
}