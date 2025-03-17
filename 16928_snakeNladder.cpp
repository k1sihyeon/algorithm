#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int N, M;

enum {
    NORMAL,
    LADDER,
    SNAKE
};

int board[101];     // snake and ladder
bool visited[101];

int BFS() {
    queue<pair<int, int>> q;    // <위치, 횟수>
    q.push({1, 0});
    visited[1] = true;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        visited[cur] = true;
        q.pop();

        if (cur == 100)
            return cnt;

        for (int i = 1; i <= 6; i++) {
            int nxt = cur + i;

            if (nxt > 100 || visited[nxt])
                continue;
            
            if (board[nxt] > 0)
                nxt = board[nxt];

            q.push({nxt, cnt+1});
        }
    }

    return EXIT_FAILURE;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    fill(&board[0], &board[100], 0);
    fill(&visited[0], &visited[100], false);

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        board[x] = y;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;

        board[u] = v;
    }

    int result = BFS();

    if (result != EXIT_FAILURE)
        cout << result << "\n";

    return EXIT_SUCCESS;
}