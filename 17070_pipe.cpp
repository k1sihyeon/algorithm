#include <iostream>
#include <vector>

using namespace std;

int N;
int result = 0;

vector<vector<int>> house;
vector<vector<bool>> visited;

enum space {
    EMPTY,
    WALL
};

enum dir {
    HORIZONTAL,
    VERTICAL,
    DIAGONAL
};

// horz, vert, diag
const int dx[3] = {0, 1, 1};
const int dy[3] = {1, 0, 1};

void dfs(int x, int y, int dir) {
    if ((x == N-1) && (y == N-1)) {
        result += 1;
        return;
    }

    for (int i = 0; i < 3; i++) {
        if ((dir == dir::HORIZONTAL && i == dir::VERTICAL))
            continue;
        
        if ((dir == dir::VERTICAL && i == dir::HORIZONTAL))
            continue;

        int nx = x + dx[i];
        int ny = y + dy[i];

        // 가장자리 및 벽 검사
        if (nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] || house[nx][ny] == space::WALL)
            continue;

        if (i == dir::DIAGONAL) {
            if ((house[nx-1][ny] == space::EMPTY) && (house[nx][ny-1] == space::EMPTY)) {
                dfs(nx, ny, i);
                visited[nx][ny] = false;
            }
        }
        else {
            dfs(nx, ny, i);
            visited[nx][ny] = false;
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;

    house.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;

            house[i][j] = val;
        }
    }

    dfs(0, 1, 0);

    cout << result << "\n";

    return 0;
}
