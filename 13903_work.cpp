#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, N;

int sidewalk[1001][1001];
//int dist[1001][1001];
bool visited[1001][1001];

int dx[11];
int dy[11];

queue<pair<pair<int, int>, int>> q;

int BFS() {
    
    int minimum = 987654321;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (x == R)
            minimum = min(minimum, dist);

        for (int i = 0; i < N; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 1) && (nx <= R) && (ny >= 1) && (ny <= C)) {
                if (!visited[nx][ny] && (sidewalk[nx][ny] == 1)) {
                    q.push({{nx, ny}, dist + 1});
                    visited[nx][ny] = true;
                }
            }
        }
    }

    if (minimum == 987654321)
        minimum = -1;

    return minimum;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // init
    // memset(sidewalk, 0, sizeof(sidewalk));
    // memset(visited, false, sizeof(visited));
    // //memset(dist, 0, sizeof(dist));
    // memset(dx, 0, sizeof(dx));
    // memset(dy, 0, sizeof(dy));

    // input
    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            int num;
            cin >> num;
            sidewalk[i][j] = num;

            if ((num == 1) && (i == 1)) {
                q.push({{i, j}, 0});
                visited[i][j] = true;
            }
        }
    }

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> dx[i] >> dy[i];

    cout << BFS() << "\n";

    return 0;
}