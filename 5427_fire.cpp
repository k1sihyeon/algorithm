#include <bits/stdc++.h>
using namespace std;

#define EMPTY   '.'
#define WALL    '#'
#define PERSON  '@'
#define FIRE    '*'

int w, h;

char building[1001][1001];
int fireDist[1001][1001];
int persDist[1001][1001];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

pair<int, int> now;
queue<pair<int, int>> fire;

template <typename T>
void print(T arr[][1001]) {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++)
            cout << arr[i][j];
        
        cout << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {

        //init
        memset(fireDist, 0, sizeof(fireDist));
        memset(persDist, 0, sizeof(persDist));
        
        queue<pair<int, int>> fq;   //fire
        queue<pair<int, int>> pq;   //person

        bool escape = false;

        //input
        cin >> w >> h;
        
        for (int i = 1; i <= h; i++) {
            for (int j = 1; j <= w; j++) {
                char c;
                cin >> c;

                building[i][j] = c;

                if (c == PERSON) {
                    pq.push({i, j});
                    persDist[i][j] = 1;
                }

                if (c == FIRE) {
                    fq.push({i, j});
                    fireDist[i][j] = 1;
                }

                if (c == WALL) {
                    //
                }
                    
            }
        }

        // fire bfs 끝까지 - 번진 시간(거리) 저장
        while (!fq.empty()) {
            int x = fq.front().first;
            int y = fq.front().second;
            fq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                if ((nx > 0) && (nx <= h) && (ny > 0) && (ny <= w)) {
                    if ((fireDist[nx][ny] == 0) && (building[nx][ny] != WALL)) {
                        fireDist[nx][ny] = fireDist[x][y] + 1;
                        fq.push({nx, ny});
                    }
                }
            }
        }

        // person bfs 끝까지 - 불이 번진 시간 전에는 방문 가능하도록
        while ((!pq.empty()) && (!escape)) {
            int x = pq.front().first;
            int y = pq.front().second;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int nx = dx[i] + x;
                int ny = dy[i] + y;

                //가장자리 범위 벗어나면 탈출임
                if (nx <= 0 || nx > h || ny <= 0 || ny > w) {   
                    cout << persDist[x][y] << "\n";
                    escape = true;
                    break;
                }

                if ((building[nx][ny] != WALL) && (persDist[nx][ny] == 0)) {
                    if ((fireDist[nx][ny] == 0) || (fireDist[nx][ny] > persDist[x][y] + 1)) {
                        persDist[nx][ny] = persDist[x][y] + 1;
                        pq.push({nx, ny});
                    }
                }
            }
        }

        if (!escape) cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}