#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> parents;

void BFS();
void DFS(int cur);

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N;
    cin >> N;

    // init
    graph.resize(N+1);
    parents.assign(N+1, 0);
    parents[1] = -1;    // root 설정

    // input
    for (int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    BFS();
    DFS(1);

    for (int i = 2; i <= N; i++) {
        cout << parents[i] << "\n";
    }

    return EXIT_SUCCESS;
}

void BFS() {
    queue<int> q;
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto & next : graph[cur]) {
            if (parents[next] == 0) {    // if not visited
                parents[next] = cur;
                q.push(next);
            }
        }
    }
}

void DFS(int cur) {
    for (const auto & next : graph[cur]) {
        if (parents[next] == 0) {       // if not visited
            parents[next] = cur;
            DFS(next);
        }
    }
}