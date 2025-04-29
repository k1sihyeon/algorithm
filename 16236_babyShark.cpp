#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> fishTank;

int travelTime = 0;

int sharkSize = 2;
int sharkAteCount = 0;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

enum State {
    EMPTY = 0,
    SHARK = 9,
};

struct Fish {
    int x;
    int y;
    int dist;
};

bool cmp(Fish &a, Fish &b) {
    if (a.dist == b.dist) {
        if (a.x == b.x)
            return a.y < b.y;
        
        return a.x < b.x;
    }

    return a.dist < b.dist;
}

Fish BFS(pair<int, int> shark) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(N, -1));
    vector<Fish> candidates;

    q.push(shark);
    visited[shark.first][shark.second] = 0; 

    while (!q.empty()) {
        int x = q.front().first;    
        int y = q.front().second;
        // auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx < 0) || (ny < 0) || (nx >= N) || (ny >= N))
                continue;
            
            if ((visited[nx][ny] != -1) || (fishTank[nx][ny] > sharkSize))
                continue;

            visited[nx][ny] = visited[x][y] + 1;    // 누적 방문 횟수(거리) 기록
            
            // 먹을 수 있는 물고기 찾아서 좌표/거리 기록
            if ((fishTank[nx][ny] != State::EMPTY) && (fishTank[nx][ny] < sharkSize))
                candidates.push_back({nx, ny, visited[nx][ny]});

            q.push({nx, ny});
        }
    }

    if (candidates.empty())
        return {-1, -1, -1};

    sort(candidates.begin(), candidates.end(), cmp);

    return candidates[0];
}

int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    fishTank.assign(N, vector<int>(N));

    pair<int, int> shark;

    // input
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;

            fishTank[i][j] = num;

            if (num == State::SHARK) {
                shark = {i, j};
                fishTank[i][j] = State::EMPTY;
            }
        }
    }

    while (true) {
        Fish target = BFS(shark);
        if (target.dist == -1)  // 먹을 수 있는 물고기가 없으면 종료
            break;

        // 먹기
        shark = {target.x, target.y};
        fishTank[target.x][target.y] = State::EMPTY;
        
        travelTime += target.dist;
        sharkAteCount += 1;

        if (sharkAteCount == sharkSize) {
            sharkSize += 1;
            sharkAteCount = 0;
        }
    }

    cout << travelTime << "\n";

    return EXIT_SUCCESS;
}