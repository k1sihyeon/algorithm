#include <bits/stdc++.h>

using namespace std;

int maps[100][100];
int dist[100][100];
bool visited[100][100];
int N, M;
int radX, radY;
int ans = 0;
int nDie = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// infection
void BFS() {
    queue<pair<int, int>> q;
    q.push({radX, radY});
    visited[radX][radY] = true;
    dist[radX][radY] = 0; 

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && (visited[nx][ny] == false)) {
                if (maps[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));

                    ans = max(dist[nx][ny], ans);
                }        
            }
        }
    }
}

void checkNotDied() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if ((visited[i][j] == false) && (maps[i][j] == 1))
                nDie += 1;
        }
    }
}

void print(int arr[][100]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << arr[i][j];
        
        cout << "\n";
    }
}

int main(void) {
    memset(dist, 0, sizeof(dist));
    memset(maps, 0, sizeof(maps));
    memset(visited, false, sizeof(visited));

    cin >> M >> N;

    for (int i = 0; i < N; i++) {

        string s;
        cin >> s;

        for (int j = 0; j < M; j++) {
            maps[i][j] = s[j] - '0';
        }
    }

    cin >> radY >> radX;
    radY -= 1;
    radX -= 1;

    BFS();
    checkNotDied();

    cout << ans + 3 << "\n";
    cout << nDie << "\n";


    return 0;
}