#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int cnt = 0;
int arr[25][25];
int visited[25][25] = {0, };

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0 ,0};

vector<int> result;

void dfs(int x, int y) {

    for (int i = 0; i < 4; i++) {
        int nextX = x + dx[i];
        int nextY = y + dy[i];

        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
            if ((arr[nextX][nextY] == 1) && (visited[nextX][nextY] == 0)) {
                visited[nextX][nextY] = 1;
                cnt++;
                dfs(nextX, nextY);
            }
        }
    }
}

void dfsAll() {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1 && visited[i][j] == 0) {
                visited[i][j] = 1;
                cnt = 1;
                dfs(i, j);
                result.push_back(cnt);
            }
        }
    }
}

int main(void) {
    string tmp;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> tmp;

        for (int j = 0; j < N; j++) {
            arr[i][j] = tmp[j] - '0';
        }
    }

    dfsAll();

    sort(result.begin(), result.end());

    cout << result.size() << endl;

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}