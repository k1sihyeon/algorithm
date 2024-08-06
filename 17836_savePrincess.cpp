#include <bits/stdc++.h>
using namespace std;

int N, M, T;
int castle[100][100];
int dist[100][100];
bool visited[100][100];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

enum {
    EMPTY,
    WALL,
    SWORD
};

void BFS(int ix, int iy) {
    queue<pair<int, int>> q;
    q.push({ix, iy});
    visited[ix][iy] = true;
    dist[ix][iy] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && (visited[nx][ny] == false)) {
                if (castle[nx][ny] != WALL) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // init variable
    memset(castle, 0, sizeof(castle));
    memset(dist, 0, sizeof(dist));
    memset(visited, false, sizeof(visited));
    pair<int, int> sword;

    int soldierToPrincess;
    int soldierToSword;
    int swordToPrincess;

    // input
    cin >> N >> M >> T;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            castle[i][j] = num;

            if (num == SWORD)
                sword = {i, j};
        }
    }

    BFS(0, 0);

    // case 1. 벽을 피해 공주로
    // case 2. 벽을 피해 검까지 + 벽 무시하고 검에서 공주로
    soldierToPrincess = dist[N-1][M-1];
    soldierToSword = dist[sword.first][sword.second];
    swordToPrincess = ((N - 1) - sword.first) + ((M - 1) - sword.second);
    // 칼에서 공주까지는 벽을 무시하고 직선으로!

    int minTime;

    // 용사가 검까지 도달하지 못하고 용사가 공주까지 도달하지 못하면 -> 실패
    if ((soldierToPrincess == 0) && (soldierToSword == 0)) {
        cout << "Fail" << "\n";
        return 0;
    }
    
    // 2개의 case 중에 도달할 수 없는 값(0)이면 다른 값으로 갱신
    if (soldierToPrincess == 0)
        minTime = soldierToSword + swordToPrincess;
    
    else if (soldierToSword == 0)
        minTime = soldierToPrincess;
    
    else
        minTime = min(soldierToPrincess, soldierToSword + swordToPrincess);
    
    // 2개의 case 중에 작은 것이 T보다 크면 -> 실패
    if (minTime > T)
        cout << "Fail" << "\n";
    else
        cout << minTime << "\n";

    return 0;
}
