#include <iostream>
#include <queue>

using namespace std;

int N, M;
int maze[101][101];
int visited[101][101];
int dist[101][101];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = 1;

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && (maze[nx][ny] == 1) && (visited[nx][ny] == 0)) {
                visited[nx][ny] = 1;
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

}

int main(void) {
    cin >> N >> M;

    //input
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            maze[i][j] = tmp[j] - '0';
        }
    }

    bfs();

    cout << dist[N-1][M-1] + 1 << endl;

    return 0;
}