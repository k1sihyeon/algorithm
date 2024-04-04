#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N, M, result = 0;
char map[601][601];
bool visited[601][601];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

pair<int, int> start;
queue<pair<int, int>> q;

void BFS() {
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();


        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M) && !visited[nx][ny]) {
                if (map[nx][ny] != 'X') {
                    if (map[nx][ny] == 'P')
                        result++;

                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(visited, false, sizeof(visited));

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < M; j++) {
            map[i][j] = str[j];

            if (map[i][j] == 'I')
                start = {i, j};
        }        
    }

    q.push(start);
    visited[start.first][start.second] = true;

    BFS();

    if (result == 0)
        cout << "TT" << "\n";
    else
        cout << result << "\n"; 

    return 0;
}