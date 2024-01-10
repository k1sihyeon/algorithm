#include <iostream>
using namespace std;

int N, M, result;
int map[1001][1001] = { 0, };
bool visited[1001] = { false, };

void dfs(int p) {
    visited[p] = true;

    for (int i = 1; i <= N; i++) {
        if ((map[p][i] == 1) && (visited[i] == false))
            dfs(i);
    }
}

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        map[u][v] = 1;
        map[v][u] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i] == false) {
            result++;
            dfs(i);
        }
    }

    cout << result << endl;

    return 0;
}