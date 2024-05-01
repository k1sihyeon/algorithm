#include <iostream>

using namespace std;

int map[501][501];
int dp[501][501];
int N, M;
int result = 0;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int DFS(int x, int y) {
    if (x == M && y == N) 
        return 1;

    if (dp[x][y] == -1) {
        dp[x][y] = 0;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 1 && nx <= M && ny >= 1 && ny <= N)
                if (map[x][y] > map[nx][ny])
                    dp[x][y] += DFS(nx, ny);
        }
    }

    return dp[x][y];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    fill(&dp[0][0], &dp[501][501] + 1, -1);

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];
    
    cout << DFS(1, 1) << "\n";

    return 0;
}