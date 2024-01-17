#include <iostream>

using namespace std;

#define MAX 101

int N;
char bMap[MAX][MAX];
char nMap[MAX][MAX];
bool bVisited[MAX][MAX] = {false, }; // color blind
bool nVisited[MAX][MAX] = {false, }; // normal

int bCnt = 0;
int nCnt = 0;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, bool visited[MAX][MAX], char arr[MAX][MAX]) {
    visited[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((nx >= 0) && (nx < N) && (ny >= 0) && (ny < N) && (visited[nx][ny] == false) && (arr[nx][ny] == arr[x][y])) {
            visited[nx][ny] = true;
            dfs(nx, ny, visited, arr);
        }
    }
}

void dfsAll() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (nVisited[i][j] == false) {
                dfs(i, j, nVisited, nMap);
                nCnt++;
            }            
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (bVisited[i][j] == false) {
                dfs(i, j, bVisited, bMap);
                bCnt++;
            }
        }
    }
}


int main(void) {

    cin >> N;

    string tmp;

    for (int i = 0; i < N; i++) {
        cin >> tmp;
        for (int j = 0; j < N; j++) {
            nMap[i][j] = tmp[j]; 

            if (tmp[j] == 'G') {
                bMap[i][j] = 'R';
            }
            else {
                bMap[i][j] = tmp[j];
            }
        }
    }

    dfsAll();

    cout << nCnt << " " << bCnt << endl;


    return 0;
}