#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <queue>

using namespace std;

int map[51][51];
int tmp[51][51];

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

//vector<pair<int, int>> dust;
queue<pair<int, int>> dust;
vector<pair<int, int>> purifier;

int R, C, T;

void Print(string str = "") {
    cout << "=== (" << str << ") Print ===\n";

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";

}

void GetDust(void) {
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (map[i][j] > 0)
                dust.push(make_pair(i, j));
}

void DustDiffusion() {
    fill(&tmp[0][0], &tmp[50][50] + 1, 0);
    tmp[purifier[0].first][purifier[0].second] = -1;
    tmp[purifier[1].first][purifier[1].second] = -1; 

    while (!dust.empty()) {
        int x = dust.front().first;
        int y = dust.front().second;
        dust.pop();

        if (map[x][y] == 0 || map[x][y] == -1)
            continue;

        int cnt = 0;
        int dDust = map[x][y] / 5;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;

            if (map[nx][ny] == -1 || tmp[nx][ny] == -1)
                continue;

            // if (dDust <= 0)
            //     continue;

            tmp[nx][ny] += dDust;
            cnt++;
        }

        tmp[x][y] += map[x][y] - (dDust * cnt);
    }
}

void Air_Top() {
    int x1 = purifier[0].first;

    for (int i = x1 - 1; i > 0; i--)
            map[i][0] = map[i - 1][0];

        for (int i = 0; i < C - 1; i++)
            map[0][i] = map[0][i + 1];

        for (int i = 0; i < x1; i++)
            map[i][C - 1] = map[i + 1][C - 1];

        for (int i = C - 1; i > 1; i--)
            map[x1][i] = map[x1][i - 1];

        map[x1][1] = 0;
}

void Air_Bottom() {
    int x2 = purifier[1].first;

    for (int i = x2 + 1; i < R - 1; i++)
            map[i][0] = map[i + 1][0];

        for (int i = 0; i < C - 1; i++)
            map[R - 1][i] = map[R - 1][i + 1];

        for (int i = R - 1; i > x2; i--)
            map[i][C - 1] = map[i - 1][C - 1];

        for (int i = C - 1; i > 1; i--)
            map[x2][i] = map[x2][i - 1];

        map[x2][1] = 0;
}


void AirPurifier() {
    Air_Top();
    Air_Bottom();
}


int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(map, 0, sizeof(map));
    memset(tmp, 0, sizeof(tmp));

    cin >> R >> C >> T;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int num;
            cin >> num;
            map[i][j] = num;

            if (num > 0) {
                dust.push(make_pair(i, j));
            }

            else if (num == -1) {
                purifier.push_back(make_pair(i, j));
            }
        }
    }

    for (int i = 0; i < T; i++) {
        DustDiffusion();

        memcpy(map, tmp, sizeof(tmp));
        
        // ostringstream oss;
        // oss << "T: " << i + 1 << " ";
        // Print(oss.str() + "Diffusion");

        AirPurifier();
        // Print(oss.str() + "Purifier");

        GetDust();
    }

    int sum = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j] != -1)
                sum += map[i][j];
        }
    }

    cout << sum << "\n";

    return 0;
}