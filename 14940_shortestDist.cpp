#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int map[1001][1001];
int dist[1001][1001] = { -1, };
bool visited[1001][1001] = { false, };
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int target_x, target_y;

queue<pair<int, int>> q;


void bfs(void) {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            if (map[nx][ny] == 1 && !visited[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(dist, -1, sizeof(dist));

    cin >> N >> M;

    //input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            map[i][j] = num;

            if (num == 2) {
                q.push(make_pair(i, j));
                visited[i][j] = true;
                map[i][j] = 1;
                dist[i][j] = 0;
            }
            else if (num == 0) {
                dist[i][j] = 0;
            }
        }
    }

    bfs();

    //print
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0; 
}