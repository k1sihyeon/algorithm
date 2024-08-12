#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define MAX         1001
#define RIPE        1
#define NOT_RIPE    0
#define EMPTY       -1

int N, M, maxDist = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int box[MAX][MAX];
int dist[MAX][MAX];
bool visited[MAX][MAX];

queue<pair<int, int>> ripe;

void BFS() {
    while (!ripe.empty()) {
        int x = ripe.front().first;
        int y = ripe.front().second;
        ripe.pop();

        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M)) {
                if ((visited[nx][ny] == false) && (box[nx][ny] != EMPTY)) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    maxDist = max(maxDist, dist[nx][ny]);
                    ripe.push({nx, ny});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //init
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    int notRipeCount = 0;

    //input
    cin >> M >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            box[i][j] = num;

            if (num == RIPE)
                ripe.push({i, j});

            if (num == NOT_RIPE)
                notRipeCount += 1;
        }
    }

    // 익지 않은 토마토가 없을 경우 == 모두 익은 토마토만 있을 경우
    if (notRipeCount == 0) {
        cout << 0 << "\n";
        return 0;
    }

    BFS();

    // 익지 않은 토마토 check
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((visited[i][j] == false) && (box[i][j] == NOT_RIPE)) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    // dist 최대값 출력
    cout << maxDist << "\n";

    return 0;
}