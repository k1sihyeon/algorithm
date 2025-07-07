#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N, M, K;
int result = 0;

vector<vector<bool>> board;
vector<vector<vector<int>>> visited;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<tuple<int, int, int>> q;

enum State {
    EMPTY,
    WALL
};

void BFS() {
    q.push(make_tuple(1, 1, 0));
    visited[1][1][0] = 1;

    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int wall = get<2>(q.front());

        q.pop();

        if ((x == N) && (y == M)) {
            result = visited[x][y][wall];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 1) && (nx <= N) && (ny >= 1) && (ny <= M) && (wall <= K)) {
                if ((board[nx][ny] == State::EMPTY) && (visited[nx][ny][wall] == false)) {
                    visited[nx][ny][wall] = visited[x][y][wall] + 1;
                    q.push(make_tuple(nx, ny, wall));
                }

                if ((board[nx][ny] == State::WALL) && (wall < K) && (visited[nx][ny][wall + 1] == false)) {
                    visited[nx][ny][wall + 1] = visited[x][y][wall] + 1;
                    q.push(make_tuple(nx, ny, wall + 1)); 
                }
            }
        }
    }

    result = -1;

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // input
    cin >> N >> M >> K;

    board.assign(N+1, vector<bool>(M+1, false));
    visited.assign(N+1, vector<vector<int>>(M+1, vector<int>(K + 1, 0)));

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < M; j++)
            board[i + 1][j + 1] = (str[j] == '0') ? State::EMPTY : State::WALL;
    }

    // bfs
    BFS();

    cout << result << "\n";

    return EXIT_SUCCESS;

}