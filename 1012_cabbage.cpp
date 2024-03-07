#include <cstring>
#include <iostream>

using namespace std;

bool field[51][51] = { 0, };
bool visited[51][51] = { 0, };

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int M, N;

bool dfs(int y, int x) {

    if (visited[y][x])
        return false;
    
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx >= 0) && (nx < M) && (ny >= 0) && (ny < N) && field[ny][nx]) {
            dfs(ny, nx);
        }
    }

    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, K;

    cin >> T;

    for (int i = 0; i < T; i++) {
        int res = 0;

        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));

        cin >> M >> N >> K;

        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }
        
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < M; k++) {
                if (field[j][k] && !visited[j][k]) {
                    if (dfs(j, k))
                        res += 1;
                }
            }
        }

        cout << res << '\n';
    }

    return 0;
}