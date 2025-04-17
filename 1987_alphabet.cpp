#include <iostream>
#include <vector>

using namespace std;

int R, C;
int result = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> board;
vector<bool> visited;

void dfs(int x, int y, int dist) {
    visited[board[x][y]] = true;
    result = max(dist, result);

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= R || ny >= C || visited[board[nx][ny]])
            continue;
        
        dfs(nx, ny, dist + 1);
        visited[board[nx][ny]] = false;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> R >> C;

    board.assign(R, vector<int>(C, 0));
    visited.assign(26, false);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            
            board[i][j] = (int)c - 'A';
        }
    }

    dfs(0, 0, 1);

    cout << result << "\n";

    return EXIT_SUCCESS;
}