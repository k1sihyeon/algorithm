#include <iostream>
#include <queue>

using namespace std;

int M, N, H;

int box[101][101][101] = { 0, };

int dx[] = {0, 0, -1, 1, 0, 0};
int dy[] = {-1, 1, 0, 0, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};

queue<pair<pair<int, int>, int>> ripe;

void bfs() {
    while (!ripe.empty()) {
        int x = ripe.front().first.first;
        int y = ripe.front().first.second;
        int z = ripe.front().second;

        ripe.pop();

        for(int i = 0; i < 6; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];

            if (
                (nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && (nz >= 0) && (nz < H) && (box[nz][nx][ny] == 0)
            ) {
                box[nz][nx][ny] = box[z][x][y] + 1;
                ripe.push(make_pair(make_pair(nx, ny), nz));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> H;

    //input
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                cin >> box[i][j][k];

                if(box[i][j][k] == 1)
                    ripe.push(make_pair(make_pair(j, k), i));
            }
        }
    }

    bfs();

    //check
    int result = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < M; k++) {
                if(box[i][j][k] == 0) {
                    cout << -1 << "\n";
                    return 0;
                }

                result = max(result, box[i][j][k]);
            }
        }
    }

    cout << result - 1 << "\n";

    return 0;
}