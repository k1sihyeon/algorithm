#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M, result = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int map[8][8] = {0, };
int tmpMap[8][8] = {0, };

vector<pair<int, int>> virus;
vector<pair<int, int>> wall;
vector<pair<int, int>> space;

//bfs로 바이러스 퍼뜨리기
void BFS() {

    //바이러스 퍼뜨릴 맵 복사
    int cntVirusMap[8][8] = {0, };
    memcpy(cntVirusMap, tmpMap, sizeof(tmpMap));

    //바이러스를 큐에 넣기
    queue<pair<int, int>> q;
    for(int i = 0; i < virus.size(); i++)
        q.push(virus[i]);
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M)) {
                if (cntVirusMap[nx][ny] == 0) {
                    cntVirusMap[nx][ny] = 2;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }

    //안전영역 크기 구하기
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cntVirusMap[i][j] == 0)
                cnt += 1;
        }
    }

    //안전 영역의 최대값 구하기
    result = max(result, cnt);
}

//벽 세우기
void BuildWall(int cnt) {   //cnt: 벽을 세운 횟수

    //벽을 다 세웠으면  //cnt: 벽을 세운 횟수
    if (cnt == 3) {
        BFS();  //바이러스 퍼뜨리기 -> 안전영역 크기 구하기
        return;
    }

    //벽 세우기 조합
    for (int i = 0; i < space.size(); i++) {
        if (tmpMap[space[i].first][space[i].second] == 0) { 
            tmpMap[space[i].first][space[i].second] = 1; //벽 세우기
            BuildWall(cnt + 1);  //재귀로 다음 벽 세우기
            tmpMap[space[i].first][space[i].second] = 0; //벽 허물기
        }
    }
    //위 반복문을 통해 3개의 벽을 세우는 모든 경우의 수를 다 구함
}


int main(void) {
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int num;
            cin >> num;
            map[i][j] = num;

            if (num == 0) {
                space.push_back(make_pair(i, j));
            }
            else if (num == 1) {
                wall.push_back(make_pair(i, j));
            }
            else if (num == 2) {
                virus.push_back(make_pair(i, j));
            }
        }
    }

    //벽을 세우기
    for (int i = 0; i < space.size(); i++) {
        memcpy(tmpMap, map, sizeof(map));
        tmpMap[space[i].first][space[i].second] = 1; //벽 세우기
        BuildWall(1);  //벽을 세운 횟수
        tmpMap[space[i].first][space[i].second] = 0; //벽 허물기
    }
    //tmpMap에 벽을 세운 후, 바이러스를 퍼뜨리고 안전영역 크기 구하기

    cout << result << "\n";

    return 0;
}