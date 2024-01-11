#include <iostream>
#include <queue>

using namespace std;

int M, N;

int box[1001][1001] = { 0, };
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

queue<pair<int, int>> ripe;

void bfs() {
    while (!ripe.empty()) {
        int x = ripe.front().first;
        int y = ripe.front().second;
        ripe.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && (box[nx][ny] == 0)) {
                box[nx][ny] = box[x][y] + 1;
                ripe.push(make_pair(nx, ny));
            }
        }
    }
}

int main(void) {
    int result = 0;

    cin >> M >> N;

    //input
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> box[i][j];
            if(box[i][j] == 1) {
                ripe.push(make_pair(i, j));
            }
        }
    }

    //bfs
    bfs();

    //check
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(box[i][j] == 0) {
                cout << -1 << endl;
                return 0;
            }

            result = max(result, box[i][j]);
        }
    }

    cout << result - 1 << endl;

    return 0;
}