#include <bits/stdc++.h>

using namespace std;

int M, N, H;
int box[100][100][100] = {0, };
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {-1, 1, 0, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

queue<pair<pair<int, int>, int>> ripe;

void bfs() {
    while (!ripe.empty()) {
        int x = ripe.front().first.first;
        int y = ripe.front().first.second;
        int z = ripe.front().second;

        ripe.pop();

        for (int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && (nz >= 0) && (nz < H)) {
                if (box[nz][nx][ny] == 0) {
                    box[nz][ny][nx] = box[z][y][x] + 1;
                    ripe.push({{nx, ny}, nz});
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //memset(box, 0, sizeof(box));

    //input
    cin >> M >> N >> H;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                cin >> box[i][j][k];

                if(box[i][j][k] == 1)
                    ripe.push({{j, k}, i});
            }
        }
    }    

    bfs();

    int ans = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (box[i][j][k] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }

                ans = max(ans, box[i][j][k]);
            }
        }
    }

    cout << ans - 1 << "\n";

    return 0;
}