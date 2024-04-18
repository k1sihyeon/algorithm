#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int result = 0;
int map[500][500];
bool visited[500][500];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int rx[4][4] = { {0, 0, 0, 1}, {0, 0, 0, -1}, {0, 1, 2, 1}, {0, 1, 2, 1} };
int ry[4][4] = { {0, 1, 2, 1}, {0, 1, 2, 1}, {0, 0, 0, 1}, {0, 0, 0, -1} };

void Rotate(int x, int y) { //ㅗ모양 예외 처리 -> err
    for (int i = 0; i < 4; i++) {
        int sum = 0;

        for (int j = 0; j < 4; j++) {
            int nx = x + rx[i][j];
            int ny = y + ry[i][j];

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
                sum += map[nx][ny];
            else
                goto next;
        }

        result = max(result, sum);
        next:;
    }
}

void DFS(int x, int y, int depth, int sum) {
    if (depth == 4) {
        result = max(result, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                DFS(nx, ny, depth + 1, sum + map[nx][ny]);
                visited[nx][ny] = false;
            }
        }
    }

    Rotate(x, y);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, false, sizeof(visited));

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(i, j, 1, map[i][j]);
            visited[i][j] = false;
        }
    }

    cout << result << '\n';

    return 0;
}