#include <iostream>
#include <queue>

using namespace std;

int N, M, result = -1;

int map[1001][1001];
int visited[1001][1001][2]; //벽 박살 여부

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<pair<int, int>, int>> q; //x, y, 벽 부순 횟수

void BFS() {
    q.push({{1, 1}, 0});
    visited[1][1][0] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;

        q.pop();

        if ((x == N) && (y == M)) {
            result = visited[x][y][wall];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 1) && (nx <= N) && (ny >= 1) && (ny <= M)) {

                if ((map[nx][ny] == 0) && (visited[nx][ny][wall] == 0)) {
                    visited[nx][ny][wall] = visited[x][y][wall] + 1;
                    q.push({{nx, ny}, wall});
                }

                if ((map[nx][ny] == 1) && (wall == 0)) {
                    visited[nx][ny][wall + 1] = visited[x][y][wall] + 1;
                    q.push({{nx, ny}, wall + 1});
                }

            }
        }

    }

    result = -1;
    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i + 1][j + 1] = str[j] - '0';
        }
    }

    BFS();

    cout << result << '\n';

    return 0;
}