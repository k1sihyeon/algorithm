#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int result = 0;

int map[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

queue<pair<int, int>> q;

void SeperateAir_DFS(int x, int y) {

    if (map[x][y] == 0)
        map[x][y] = 2;
    else
        return;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M)) {
            if (map[nx][ny] == 0) {
                SeperateAir_DFS(nx, ny);
            }
        }
    }

}

void SetMeltCheeze() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (map[i][j] == 1) {       // 해당 칸이 치즈이고

                int cnt = 0;

                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M)) {
                        if (map[nx][ny] == 2)   // 상하좌우에 공기가 있으면
                            cnt += 1;              // 변의 개수 증가
                    }
                }

                if (cnt >= 2)                   // 변의 개수가 2개 이상이면
                    q.push({i, j});             // 해당 치즈를 녹일 예정
            
            }
        }
    }
}

void MeltCheeze() {
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        map[x][y] = 2;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < M)) {
                if (map[nx][ny] == 0)           //녹인 치즈 주변에 내부 공기가 있으면
                    SeperateAir_DFS(nx, ny);    //외부 공기로 바꿔줌
            }
        }
    }
}

void printMap() {
    cout << "====================" << "\n";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << map[i][j] << " ";
        cout << "\n";
    }

    cout << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++)
            cin >> map[i][j];
    }

    SeperateAir_DFS(0, 0);  //외부 / 내부 공기 구분

    //printMap();

    while (true) {
        SetMeltCheeze();    //녹일 치즈 찾기 (외부공기 2개 이상)

        if (q.empty())      //녹일 치즈가 없으면 종료
            break;

        MeltCheeze();       //큐에 저장된 치즈 녹이기

        result += 1;

        //printMap();
    }

    cout << result << "\n";

    return 0;
}
